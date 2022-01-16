#ifndef COMMUNICATION_LINES_H
#define COMMUNICATION_LINES_H

#include<string>
#include<unordered_map>

class Communication_lines 
{
    public:
        Communication_lines() = default;
        void add_to_list(const std::string& user, bool is_permitted);
        void remove_from_list(const std::string& user_to_remove);
        std::string get_item_from_list(const std::string& user_to_get) const;        
        void alter_permission(const std::string& user_current, const std::string& user_target);

        friend void load_from_file(const std::string& file_name, Communication_lines& lines);
        friend void save_to_file(const std::string& file_name, const Communication_lines& lines);
        friend std::ostream& operator<<(std::ostream& out,const Communication_lines& lines);
        friend std::istream& operator>>(std::istream& in, Communication_lines& lines);
        friend void alter_boolean(const std::string& user_current, Communication_lines& user_target);

	private:
		std::unordered_map<std::string, bool> communication_lines;
};

#endif
