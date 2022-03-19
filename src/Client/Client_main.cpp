#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cstdint>

#include <boost/asio.hpp>
#include "../includes/server_utilities.h"

std::string argv_flatener(int argc,
			  char** argv);

void execute_client(int32_t argc,
		    char** argv);

int main(int32_t argc,
	 char** argv)
{
  std::ios_base::sync_with_stdio(false);

  if(argc > 2)
    {
      execute_client(argc, argv);
    }
  else
    {
      std::cerr << "invalid argument count\n";
      return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

void execute_client(int32_t argc,
		    char** argv)
{
  using namespace boost::asio;
  std::ios_base::sync_with_stdio(false);

  try
    {
      const std::string IP_ADDR {*(argv + 1)};
      std::string       message {};

      boost::system::error_code error_code {};
      io_context                io_context {};

      ip::tcp::socket socket{io_context, ip::tcp::v4()};
      socket.connect(make_endpoint(IP_ADDR, 80));
      send_message(socket, error_code, argv_flatener(argc, argv));
      message = get_message(socket, error_code);
      
      std::cout << message;
      socket.close();
    }
  catch(std::exception& excpt)
    {
      std::cerr << excpt.what() << '\n';
    }
}

std::string argv_flatener(int32_t argc,
			  char** argv)
{
  std::vector<std::string>arguments(argv + 2, argv + argc);
  std::string flattened_args{};

  for(const auto& args : arguments)
    {
      flattened_args += args + " ";
    }

  return flattened_args;
}
