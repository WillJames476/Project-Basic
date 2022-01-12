#include <sstream>
#include <chrono>
#include <fstream>
#include <filesystem>
#include <array>
#include <vector>
#include <boost/program_options.hpp>

#include "Message_list.h"
#include "Message_tuple.h"
#include "../Utilities/io.h"

void load_from_file(const std::array<std::string, 2>& file_name, 
Message_list& messages)
{
    if(!std::filesystem::exists("users/" + file_name[0] + "/chats"))
    {
        std::filesystem::create_directory("users/" + file_name[0] + "/chats");
    }

    try
    {
        std::fstream file_to_read("users/" + file_name[0] + "/chats/" 
        + file_name[0] + "_" + file_name[1] + ".txt", std::ios_base::in);
        file_to_read >> messages;
        file_to_read.close();
    }
    catch(std::exception &s)
    {
        std::cerr << s.what();
    }
}

void add_to_chat(Message_list& subject
                ,const std::string& accessor
                ,const std::vector<std::string>& fields)
{
    using namespace REGEX_PREDICATES;

    if(static_cast<int>(fields.size()) == 1)
    {
        if(arguments_verify(fields, {MESSAGE}))
        {
            subject.add_to_list(Message_tuple{accessor, fields[0],
            std::chrono::system_clock::to_time_t(std::chrono::system_clock::now())});
        }
        else
        {
            invalid_argument_error("-add");
        }
    }
    else
    {
        invalid_argument_quantity_error("--add", 1);       
    }
}

void message_control_flow_cli(Message_list& subject 
                        ,const Message_list& second 
                        ,Message_list& temp
                        ,const std::string& accessor
                        ,const boost::program_options::options_description& description
                        ,const boost::program_options::variables_map& vm)
{
    if(vm.count("add"))
    {
        add_to_chat(subject, accessor, vm["add"].as<std::vector<std::string>>());
    }
    else if(vm.count("view"))
    {
        temp = subject + second;
        temp.print_list();
    }
    else if(vm.count("help"))
    {
        std::cout << description;
    }
}

void message_cli(int argc, char**argv, const std::array<std::string, 2>& users)
{
    using namespace boost::program_options;

    Message_list subject {},
                 second  {},
                 temp    {};
    load_from_file({users[0], users[1]}, subject);
    load_from_file({users[1], users[0]}, second);

    try
    {
        options_description options{"options"};
        options.add_options()
        ("add", value<std::vector<std::string>>()->multitoken()->composing()->zero_tokens(),
        "add a new chat")
        ("view", "views all your chats")
        ("help", "prints all available flags and options");

        variables_map vm;
        store(parse_command_line(argc, argv, options), vm);
        notify(vm);
        message_control_flow_cli(subject, second, temp, users[1], options, vm);
    }
    catch(const error& excpt)
    {
        std::cerr << excpt.what() << '\n';
    }

    std::string chat_file_name{"users/" + users[0] + "/chats/" 
    + users[0] + "_" + users[1] + ".txt"};
    
    save_to_file<Message_list>(chat_file_name, subject);
}