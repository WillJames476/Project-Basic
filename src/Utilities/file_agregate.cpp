#include <sstream>
#include "../includes/file_agregates.h"

File_agregate::File_agregate(const Model_agregate& models)
        : account{Generic_file<Account_model>{models.account, "accounts.txt"}}
        , commline{Generic_file<Commline_model>{models.commline, "commline.txt"}}
{

}

void File_agregate::save_all()
{
    auto account_write{[](auto& x)
    {
        std::string to_return{};

        for(const auto& y : x->get_accounts())
        {
            to_return += y.first + " " + y.second + "\n";
        }

        return to_return;
    }};

    auto commline_write{[](auto& x)
        {
            std::ostringstream to_return{};

            for(const auto& y : x->get_commlines())
            {
                to_return << y.first << '\n';

                for(const auto& z : y.second->get_table())
                {
                    to_return << z.first << " " << std::to_string(z.second) << '\n';
                }

                to_return << "END\n";
            }

            return to_return.str();
        }};

    save_file(account, account_write);
    save_file(commline, commline_write);
}

void File_agregate::read_all()
{
    auto account_read{[](auto& x, auto& y)
        {
            std::array<std::string, 2>fields;
            
            while(x >> fields[0] >> fields[1])
            {
                y->add_to_list(fields[0], fields[1]);
            }
        }};

    auto commline_read{[](auto& x, auto& y)
        {
            std::string extracted_string{};

            while(x >> extracted_string)
            {
                y->add_to_list(extracted_string);

                while(extracted_string != "END")
                {
                    x >> extracted_string;
                }
            }
        }};

    read_file(account, account_read);
    read_file(commline, commline_read);
}   