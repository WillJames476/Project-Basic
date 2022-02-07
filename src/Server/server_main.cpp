#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include <boost/format.hpp>
#include <boost/asio.hpp>

#include "../includes/io.h"
#include "../includes/server_utilities.h"
#include "server_control.h"

int main(int argc, char** argv)
{
    std::ios_base::sync_with_stdio(false);

    if(argc == 2)
    {
        try
        {
            std::string message{}, ip_addr{*(argv + 1)};

            boost::asio::io_context io_context{};
            boost::asio::ip::tcp::acceptor acceptor{io_context
                , make_endpoint(ip_addr, 80)};
            boost::system::error_code err_codes;

            while(true)
            {
                std::string received{};

                boost::asio::ip::tcp::socket client{io_context};
                acceptor.accept(client);

                received = get_message(client, err_codes);
                received = server_control(received);
                send_message(client, err_codes, received);

                client.close();
                
                break;
            }

            acceptor.close();
        }
        catch(std::exception& excpt)
        {   
            std::cerr << excpt.what();
        }
    }

    return 0;
}