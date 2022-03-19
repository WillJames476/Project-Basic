#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cstdlib>
#include <cstdint>

#include <boost/format.hpp>
#include <boost/asio.hpp>

#include "../includes/io.h"
#include "../includes/server_utilities.h"
#include "server_control.h"

void communication_handler(boost::asio::io_context& io_context,
			   boost::system::error_code& err_codes,
			   boost::asio::ip::tcp::acceptor& acceptor);

void execute_server(char** argv);

int main(int32_t argc, char** argv)
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

      const int32_t      PORT    {std::stoi(*(argv + 2))};
      const std::string  IP_ADDR {*(argv + 1)};
      std::string        message {};
      io_context         context {};

      ip::tcp::acceptor server   {context, make_endpoint(IP_ADDR, PORT)};

      boost::system::error_code error_code;
      communication_handler(context, error_code, server);

      server.close();
      
    }
  catch(std::exception& excpt)
    {
      std::cerr << excpt.what() << '\n';
    }
}

void communication_handler(boost::asio::io_context& io_context,
			   boost::system::error_code& err_codes,
			   boost::asio::ip::tcp::acceptor& acceptor)
{
  std::ios_base::sync_with_stdio(false);
  std::string received{};

  while(true)
    {
      
      boost::asio::ip::tcp::socket client{io_context};
      acceptor.accept(client);

      received = get_message(client, err_codes);
      received = server_control(received);
      send_message(client, err_codes, received);

      std::cout << received;
      client.close();

      if(received == "END")
	{
	  break;
	}
    }
}
