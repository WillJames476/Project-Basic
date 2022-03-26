#include <array>

#include <boost/format.hpp>
#include "Account_view.h"

Account_view::Account_view(const std::shared_ptr<Account_model>& model)
    : model_ptr{model}
{
}

std::string
Account_view::send_formatted(const std::string& account_name) const
{
  const auto& credentials{model_ptr->get_account(account_name)};
  std::ostringstream to_return;

  to_return << boost::format("\n|Username: %-10sPassword: %-10s|\n")
    % credentials.first
    % credentials.second;

  return to_return.str();
}

std::ostringstream
Account_view::send_as_stream() const
{
  std::ostringstream to_return;

  for(const auto& y : model_ptr->get_accounts())
    {
      to_return << boost::format("%s %s \n")
	% y.first
	% y.second;
    }

  return to_return;
}

void
Account_view::read_from_stream(std::istream& to_read) const
{
  std::array<std::string, 2> output;

  while(to_read >> output[0] >> output[1])
    {
      model_ptr->add_to_list(output[0], output[1]);
    }
}
