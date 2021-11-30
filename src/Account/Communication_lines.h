#ifndef COMMUNICATION_LINES_H
#define COMMUNICATION_LINES_H

#include <vector>
#include <string>

class Communication_lines
{
    private:
        std::vector<std::string> communication_lines;
    public:
        Communication_lines(const std::initializer_list<std::string>& lines);
        Communication_lines(const std::vector<std::string>& lines);
        void add_to_list(const std::string& line_to_add);
        std::vector<std::string>get_communication_lines() const;
};

#endif