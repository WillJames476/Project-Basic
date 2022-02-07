#include <iostream>
#include <boost/asio.hpp>
#include "../includes/server_utilities.h"

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);

    if(argc == 2)
    {
        try
        {
            std::string message{}, ip_addr{*(argv + 1)};
            boost::system::error_code error_code;

            boost::asio::io_context io_context;
            boost::asio::ip::tcp::socket socket(io_context, boost::asio::ip::tcp::v4());
            socket.connect(make_endpoint(ip_addr, 80));

            send_message(socket, error_code, "GET / HTTP/1.1\r\nConnection: close\r\n\r\n");
            message = get_message(socket, error_code);
            std::cout << message;

            socket.close();
        }
        catch(std::exception& excpt)
        {
            std::cerr << excpt.what() << '\n';
        }
    }

    return 0;
}