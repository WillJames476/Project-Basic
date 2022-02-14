#include <iostream>
#include <vector>
#include <string>

#include <boost/asio.hpp>
#include "../includes/server_utilities.h"

std::string argv_flatener(int argc, char** argv);

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);

    if(argc > 2)
    {
        try
        {
            std::string message{}, ip_addr{*(argv + 1)};

            boost::system::error_code error_code;
            boost::asio::io_context io_context;

            boost::asio::ip::tcp::socket socket(io_context, boost::asio::ip::tcp::v4());
            socket.connect(make_endpoint(ip_addr, 80));

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
	else
	{
		std::cerr << "invalid argument count\n";
	}

    return 0;
}

std::string argv_flatener(int argc, char** argv)
{
    std::vector<std::string>arguments(argv + 2, argv + argc);

    std::string flattened_args;

    for(const auto& args : arguments)
    {
        flattened_args += args + " ";
    }

    return flattened_args;
}
