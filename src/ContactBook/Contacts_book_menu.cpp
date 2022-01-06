#include <sstream>
#include <fstream>

#include "Contacts_book_menu.h"
#include "Contacts_list.h"
#include "Contacts.h"
#include "../Utilities/io.h"

void load_from_file(const std::string& file_name, Contacts_list& contacts)
{
    try
    {
        std::fstream file_to_load(file_name, std::ios_base::in);
        file_to_load >> contacts;
        file_to_load.close();
    }
    catch(std::exception& s)
    {
        std::cerr << s.what();
    }
}

void save_to_file(const std::string& file_name, Contacts_list& contacts)
{
    try
    {
        std::fstream file_to_load(file_name, std::ios_base::out);
        file_to_load << contacts;
        file_to_load.close();
    }
    catch(std::exception& s)
    {
        std::cerr << s.what();
    }
}

void contacts_book_control_flow(Contacts_list& contacts ,char menu_choice, 
bool& menu_replay)
{
    switch(menu_choice)
    {
        case '1':
            contacts.add_to_list
            (Contacts{get_string("enter the name here: ", 
            REGEX_PREDICATES::ALPHA_NOSPACE),
            get_string("enter the number here: ", 
            REGEX_PREDICATES::DIGIT_NOSPACE), 
			get_string("enter the email here: ",
			REGEX_PREDICATES::EMAIL)});
            break;
        case '2':
            contacts.remove_from_list
            (Contacts{get_string("enter the name here: ",
            REGEX_PREDICATES::ALPHA_NOSPACE),
            get_string("enter the number here: ",
            REGEX_PREDICATES::DIGIT_NOSPACE),
            get_string("enter the email here: ",
            REGEX_PREDICATES::EMAIL)});
            break;
        case '3':
            std::cout << contacts.get_item_from_list
            (Contacts{get_string("enter the name here: ",
            REGEX_PREDICATES::ALPHA_NOSPACE),
            get_string("enter the number here: ", 
            REGEX_PREDICATES::DIGIT_NOSPACE),
            get_string("enter the email here: ",
            REGEX_PREDICATES::EMAIL)});
            break;
        case '4':
            contacts.print_list();
            break;
        case '5':
            menu_replay = false;
            break;
    }
}

char contacts_book_menu()
{
    std::ostringstream menu;

    menu <<"\n============================\n"
        << "1\tadd a new contact\n"
        << "2\tremove a contact\n"
        << "3\tsearch a contact\n"
        << "4\tview all contacts\n"
        << "5\texit the program\n"
        << "enter your choice here: ";

    return get_integral<char>(menu.str(), '0' ,'6');
}

void contacts_book(const std::string& file_name)
{
    Contacts_list contacts{};
    bool menu_replay{true};

    load_from_file(file_name, contacts);

    while(menu_replay)
    {
        contacts_book_control_flow(contacts, contacts_book_menu()
        , menu_replay);
    }

    save_to_file(file_name, contacts);
}
