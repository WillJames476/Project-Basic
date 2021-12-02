#ifndef COMMUNICATION_LINES_H
#define COMMUNICATION_LINES_H

#include<string>
#include<unordered_map>

class Communication_lines
{
    private:
        std::unordered_map<std::string, bool>communication_lines;
    public:
        void add_to_list(const std::initializer_list<std::string>& fields);
        void remove_from_list(const std::initializer_list<std::string>& fields);
        std::string get_item_from_list(const std::initializer_list<std::string>& fields) const;
        void alter_permission(const std::string& user_current, const std::string& user_target);
        friend void load_from_file(const std::string& file_name, Communication_lines& lines);
        friend void save_to_file(const std::string& file_name, const Communication_lines& lines);
        friend std::ostream& operator<<(std::ostream& out,const Communication_lines& lines);
        friend std::istream& operator>>(std::istream& in, Communication_lines& lines);
        friend void alter_boolean(const std::string& user_current, Communication_lines& user_target);
};

#endif