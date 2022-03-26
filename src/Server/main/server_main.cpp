#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdint>
#include <thread>

#include <boost/asio.hpp>
#include <input_output/io.h>
#include <application_agregates/control_agregate.h>
#include <application_agregates/view_agregate.h>
#include <application_agregates/model_agregate.h>
#include <application_agregates/file_agregates.h>
#include <input_output/server_utilities.h>

#include "server_control.h"


const std::string APPLICATION{"Server"};

void communication_handler(boost::asio::io_context& io_context,
			   boost::system::error_code& err_codes,
			   boost::asio::ip::tcp::acceptor& acceptor,
			   const Control_agregate& control,
			   const View_agregate& view);

void execute_server(char** argv);

int main(int32_t argc,
	 char** argv)
{
  std::ios_base::sync_with_stdio(false);

  if(argc == 3)
    {
      execute_server(argv);
    }
  else
    {
      std::cerr << "argument count is not 3\n";
      return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void execute_server(char** argv)
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

void communication_handler(boost::asio::io_context& io_context,
			   boost::system::error_code& err_codes,
			   boost::asio::ip::tcp::acceptor& acceptor,
			   const Control_agregate& control,
			   const View_agregate& view)
{
  std::ios_base::sync_with_stdio(false);
  std::string received{};
  
  while(true)
    {
      boost::asio::ip::tcp::socket client{io_context};
      acceptor.accept(client);
      received = get_message(client, err_codes, APPLICATION);
      std::cout << received << '\n';
      
      received = server_control(received, control,view);
      send_message(client, err_codes, received, APPLICATION);
      
      if(received == "END")
	{
	  break;
	}
    }
}
