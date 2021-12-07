#include <sstream>

#include "Contacts_book_menu.h"
#include "Contacts_list.h"
#include "../Utilities/io.h"

void contacts_book_control_flow(Contacts_list& contacts ,char menu_choice, 
bool& menu_replay)
{
    switch(menu_choice)
    {
        case '1':
            contacts.add_to_list
            ({get_string("enter the name here: ", 
            string_predicates("Default")),
            get_string("enter the number here: ", 
            string_predicates("Contact"))});
            break;
        case '2':
            contacts.remove_from_list
            ({get_string("enter the name here: ",
            string_predicates("Default"))});
            break;
        case '3':
            std::cout << contacts.get_item_from_list
            ({get_string("enter the name here: ",
            string_predicates("Default"))});
            break;
        case '4':
            std::cout << contacts;
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

void contacts_book()
{
    Contacts_list contacts{};
    bool menu_replay{true};

    while(menu_replay)
    {
        contacts_book_control_flow(contacts, contacts_book_menu()
        , menu_replay);
    }
}