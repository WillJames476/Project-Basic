#ifndef ACCOUNT_VIEW_H
#define ACCOUNT_VIEW_H

#include <memory>
#include <sstream>

#include "account_model.h"
#include "../Interfaces/View_interface.h"

class Account_view
{
    public:
        Account_view(const std::shared_ptr<Account_model>& model);

        std::string send_formatted(const std::string& account_name) const;

        std::ostringstream send_as_stream() const;

        void read_from_stream(std::istringstream& to_read) const;

    private:
        std::shared_ptr<Account_model> model_ptr;
};

#endif
