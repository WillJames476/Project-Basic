#include <iostream>
#include <thread>
#include <string>
#include <iomanip>
#include <ctime>
#include <agregates/control_agregate.h>
#include <agregates/view_agregate.h>
#include <agregates/model_agregate.h>
#include <agregates/file_agregate.h>
#include <server_control.h>
#include <server_utilities.h>
#include <io.h>
#include <boost/format.hpp>
#include <boost/asio.hpp>

const std::string APPLICATION{"server"};

void
communication_handler(boost::asio::io_context& io_context,
		      boost::system::error_code& err_codes,
		      boost::asio::ip::tcp::acceptor& acceptor,
		      const Control_agregate& control,
		      const View_agregate& view)
{
  std::ios_base::sync_with_stdio(false);
  std::string received{};
  std::string to_send{};
  boost::asio::ip::tcp::socket client{io_context};
  acceptor.accept(client);
  
  std::thread io_operation {[&]()
  {    
    while(true)
      {
	received = get_message(client, err_codes, APPLICATION);
	to_send = server_control(received, control,view);
	send_message(client, err_codes, to_send, APPLICATION);

	if(received == "END")
	  {
	    break;
	  }
      }
  }};

  std::thread log_operation{[&]()
  {
    while(true)
      {
	std::cout << boost::format("%s %s\n")
	  % get_current_time()
	  % received;
	
	if(received == "END")
	  {
	    break;
	  }
      }
  }};

  io_operation.join();
  log_operation.join();
}

void
execute_server(char** argv)
{
  using namespace boost::asio;
  std::ios_base::sync_with_stdio(false);
  
  try
    {
      Model_agregate model     {};
      Control_agregate control {model};
      View_agregate view       {model};
      File_agregate files      {model};
      
      files.read_all();
      
      const int32_t      PORT    {std::stoi(*(argv + 2))};
      const std::string  IP_ADDR {*(argv + 1)};
      std::string        message {};
      io_context         context {};

      ip::tcp::acceptor server   {context, make_endpoint(IP_ADDR, PORT)};

      boost::system::error_code error_code;
      communication_handler(context, error_code, server, control, view);

      server.close();
      files.save_all();
    }
  catch(std::exception& excpt)
    {
      std::cerr << excpt.what() << '\n';
    }
}
