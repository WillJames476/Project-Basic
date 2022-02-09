#include <string>

#include <boost/asio.hpp>
#include <boost/format.hpp>

#include "../includes/io.h"

void error_check(const boost::system::error_code& error_codes)
{
    using namespace FEEDBACK_COLORS;

    if(error_codes)
    {
        std::cout.sync_with_stdio(false);
        std::cout << boost::format("%s%s%s\n")
            % BAD 
            % error_codes.message()
            % RESET;
    }
}

boost::asio::ip::tcp::endpoint make_endpoint(const std::string& ip_addr
                                            ,const int port_number)
{
    boost::asio::ip::tcp::endpoint endpoint{
        boost::asio::ip::address::from_string(ip_addr)
        , boost::asio::ip::port_type(port_number)};

    return endpoint;
}

std::string get_message(boost::asio::ip::tcp::socket& socket
                        , boost::system::error_code& error_codes)
{
    socket.wait(socket.wait_read);
    size_t bytes{socket.available()};
    std::vector<char>buffer(bytes);

    boost::asio::read(socket
        , boost::asio::buffer(buffer, bytes)
        , error_codes);

    error_check(error_codes);

    return std::string{buffer.begin(), buffer.end()};
}

void send_message(boost::asio::ip::tcp::socket& socket
                , boost::system::error_code& error_codes
                , const std::string& message)
{
    socket.wait(socket.wait_write);

    boost::asio::write(socket
        , boost::asio::buffer(message, message.size())
        , error_codes);
    
    error_check(error_codes);
}