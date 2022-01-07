#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <unordered_map>

#include "Users_list.h"
#include "Account_menu.h"
#include "../Utilities/io.h"

Account create_account(const std::vector<std::string>&requests)
{
    int tracker{0};
    std::array<std::string, 2>account_credentials;

    while(tracker < static_cast<int>(account_credentials.size()))
    {
        account_credentials[tracker] = get_string(requests[tracker], 
        REGEX_PREDICATES::ALPHA_NOSPACE);
        tracker++;
    }

    return Account{account_credentials[0], account_credentials[1]};
}

void accounts_manager_control_flow(std::string& user_file, 
char menu_choice,bool& menu_replay, Users_list &accounts)
{
    const std::vector<std::string> requests{"enter the username here: ",
    "enter the password here: "};
    const std::vector<std::string> predicates{"Default", "Default"};
    
    switch (menu_choice)
    {
        case '1':
            accounts.add_to_list
            ({get_string("enter the user name here: ", REGEX_PREDICATES::ALPHA_NOSPACE), 
            get_string("enter the password here:" ,REGEX_PREDICATES::ALPHA_NOSPACE),"1"});
            break;
        case '2':
            accounts.remove_from_list(create_account(requests));
            break;
        case '3':
            user_file = accounts.get_item_from_list
            (create_account(requests)).get_credential().first;
            break;
        case '4':
            menu_replay = false;
            break;
    }
}

char accounts_manager_menu()
{
    std::ostringstream menu;
    menu  << "\n=================================\n"
          << "1\tadd a user\n"
          << "2\tremove a user\n"
          << "3\tuser login\n"
          << "4\texit login sector\n"
          << "enter your choice here: ";
    return get_integral<char>(menu.str(),'0','5');
}

std::string accounts_manager(const std::string& accounts_file)
{
    Users_list accounts{};
    std::string menu_choice{}, user_file{};
    bool menu_replay{true};

    load_from_file<Users_list>(accounts_file, accounts);

    while(menu_replay)
    {
        accounts_manager_control_flow(user_file,accounts_manager_menu(),
        menu_replay, accounts);
    }

    save_to_file<Users_list>(accounts_file, accounts);
    return user_file;
}
