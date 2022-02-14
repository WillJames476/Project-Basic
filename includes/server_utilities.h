#ifndef SERVER_UTILITIES_H
#define SERVER_UTILITIES_H

#include <string>
#include <boost/asio.hpp>

boost::asio::ip::tcp::endpoint make_endpoint(const std::string& ip_addr
                                            ,const unsigned short port_number);

std::string get_message(boost::asio::ip::tcp::socket& socket
                        , boost::system::error_code& error_codes);

void send_message(boost::asio::ip::tcp::socket& socket
                , boost::system::error_code& error_codes
                , const std::string& message);

#endif
