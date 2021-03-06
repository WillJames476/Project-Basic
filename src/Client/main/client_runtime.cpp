#include <boost/asio.hpp>
#include <string>
#include <iostream>
#include <io.h>
#include <server_utilities.h>

const std::string APPLICATION{"client"};

void
client_runtime(boost::asio::ip::tcp::socket& socket,
	       boost::system::error_code& error_code)
{
  std::ios_base::sync_with_stdio(false);
  std::string message{};

  while(message != "END")
    {
      message = get_string("\nClient runtime> ", REGEX_PREDICATES::COMMAND);
      send_message(socket, error_code,message, APPLICATION);
      std::cout << get_message(socket, error_code, APPLICATION);
    }
}

void
execute_client(char** argv)
{
  using namespace boost::asio;
  std::ios_base::sync_with_stdio(false);

  try
    {
      const std::string IP_ADDR {*(argv + 1)};
      const int32_t     PORT{std::stoi(*(argv + 2))};
      std::string       message {};

      boost::system::error_code error_code {};
      io_context                io_context {};

      ip::tcp::socket socket{io_context, ip::tcp::v4()};
      socket.connect(make_endpoint(IP_ADDR, PORT));
      client_runtime(socket, error_code);
      socket.close();
    }
  catch(std::exception& excpt)
    {
      std::cerr << excpt.what() << '\n';
    }
}


