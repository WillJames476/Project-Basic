#ifndef SERVER_RUNTIME_HPP
#define SERVER_RUNTIME_HPP

#include <boost/asio.hpp>
#include <agregates/control_agregate.h>
#include <agregates/view_agregate.h>

void
execute_server(char** argv);

void
communication_handler(boost::asio::io_context& io_context,
			   boost::system::error_code& err_codes,
			   boost::asio::ip::tcp::acceptor& acceptor,
			   const Control_agregate& control,
			   const View_agregate& view);

#endif //SERVER_RUNTIME_HPP
