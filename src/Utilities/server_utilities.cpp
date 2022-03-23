#include <string>

#include <boost/asio.hpp>
#include <boost/format.hpp>

#include "../includes/io.h"

void error_check(const boost::system::error_code& error_codes,
		 const std::string& location_function,
		 const std::string& location_application)
{
    using namespace FEEDBACK_COLORS;

    if(error_codes)
    {
        std::cout.sync_with_stdio(false);
        std::cout << boost::format("%s%s-%s: %s%s\n")
	  % BAD
	  % location_application
	  % location_function
	  % error_codes.message()
	  % RESET;
    }
}

boost::asio::ip::tcp::endpoint make_endpoint(const std::string& ip_addr
                                            ,const unsigned short port_number)
{
    boost::asio::ip::tcp::endpoint endpoint{
        boost::asio::ip::address::from_string(ip_addr)
        , port_number};

    return endpoint;
}

std::string get_message(boost::asio::ip::tcp::socket& socket,
			boost::system::error_code& error_codes,
			const std::string& location)
{
    socket.wait(socket.wait_read);
    size_t bytes{socket.available()};
    std::vector<char>buffer(bytes);

    boost::asio::read(socket
        , boost::asio::buffer(buffer, bytes)
        , error_codes);

    error_check(error_codes, location, "read socket");

    return std::string{buffer.begin(), buffer.end()};
}

void send_message(boost::asio::ip::tcp::socket& socket,
		  boost::system::error_code& error_codes,
		  const std::string& message,
		  const std::string& location)
{
    socket.wait(socket.wait_write);

    boost::asio::write(socket
        , boost::asio::buffer(message, message.size())
        , error_codes);
    
    error_check(error_codes, location, "write socket");
}
