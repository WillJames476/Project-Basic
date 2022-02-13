#ifndef GENERIC_FILE_H
#define GENERIC_FILE_H

#include <string>
#include <type_traits>
#include <memory>
#include <fstream>
#include <iostream>

template<typename T>
struct Generic_file
{
    public:
        Generic_file(const std::shared_ptr<T>& target
                    , const std::string& file_name);

        template<typename X, typename write_func>
        friend void save_file(const X& object
                        , const write_func& function);

        template<typename Y, typename read_func>
        friend void read_file(Y& to_modify
                        , const read_func& function);

    private:
        std::shared_ptr<T> object;
        std::string file_path{};
};

template <typename T>
Generic_file<T>::Generic_file(const std::shared_ptr<T>& target
                            , const std::string& file_name)
    : object{target}, file_path{file_name}
{
}

template <typename X, typename write_func>
void save_file(const X& object, const write_func& function)
{
    try
    {
        auto file_to_use{std::ofstream(object.file_path)};
        file_to_use << function(object.object);
        file_to_use.close();
    }
    catch(const std::exception &excpt)
    {
        std::cout << excpt.what() << " " << object.file_path << '\n';
    }
}

template <typename Y, typename read_func>
void read_file(Y& to_modify, const read_func& function)
{
    try
    {
        auto file_to_use{std::ifstream(to_modify.file_path)};
        function(file_to_use, to_modify.object);
        file_to_use.close();
    }
    catch(const std::exception &excpt)
    {
        std::cout << excpt.what() << " " << to_modify.file_path << '\n';
    }
}


#endif