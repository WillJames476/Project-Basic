#ifndef CLIENT_RUNTIME_HPPP
#define CLIENT_RUNTIME_HPP

#include <boost/asio.hpp>

void
execute_client(char** argv);

void
client_runtime(boost::asio::ip::tcp::socket& socket,
	       boost::system::error_code& error_code);

#endif //CLIENT_RUNTIME_HPP
