#include <algorithm>
#include "Communication_lines.h"

Communication_lines::Communication_lines(const std::initializer_list<std::string>& lines)
: communication_lines{lines}
{

}

Communication_lines::Communication_lines(const std::vector<std::string>& lines)
: communication_lines{lines}
{

}


void Communication_lines::add_to_list(const std::string& line_to_add)
{
    if(std::none_of(this->communication_lines.begin(), 
    this->communication_lines.end(),
    [line_to_add](auto test)
    {return line_to_add == test;}))
    this->communication_lines.push_back(line_to_add);
}

std::vector<std::string> Communication_lines::get_communication_lines() const
{
    return this->communication_lines;
}