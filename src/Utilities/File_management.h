#ifndef FILE_MANAGEMENT_H
#define FILE_MANAGEMENT_H

class File_management
{
    public:
        virtual void save_to_file(const std::string& file_name) = 0;
        virtual void load_from_file(const std::string& file_name) = 0;
};

#endif