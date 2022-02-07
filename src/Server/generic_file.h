#ifndef GENERIC_FILE_H
#define GENERIC_FILE_H

#include <string>
#include <type_traits>
#include <memory>
#include <fstream>
#include <iostream>

template<typename T, typename func_read, typename func_write>
struct Generic_file
{
    public:
        Generic_file(const T& target
                    , func_read& read_func
                    , const func_write& write_func);
        ~Generic_file();

        void save_file();
        void read_file();

    private:
        std::shared_ptr<T> object;

        func_read output_function;
        func_write input_function;

        std::string file_path{};
        std::fstream file_to_use;
};

template <typename T, typename func_read, typename func_write>
Generic_file<T, func_read, func_write>::Generic_file(const T& target
                                                , func_read& read_function
                                                , const func_write& write_function)
    : object{std::make_shared<T>(target)}
        , output_function{read_function}
        , input_function(write_function)
{

}

template <typename T, typename func_read, typename func_write>
Generic_file<T, func_read, func_write>::~Generic_file()
{
    file_to_use.close();
}

template <typename T, typename func_read, typename func_write>
void Generic_file<T, func_read, func_write>::save_file()
{
    try
    {
        file_to_use << input_function(object);
    }
    catch(const std::exception &excpt)
    {
        std::cout << excpt.what() << '\n';
    }
}

template <typename T, typename func_read, typename func_write>
void Generic_file<T, func_read, func_write>::read_file()
{
    try
    {
        file_to_use = std::fstream(file_path
                                , std::ios_base::in 
                                    | std::ios_base::out);

        output_function(object);
    }
    catch(const std::exception &excpt)
    {
        std::cout << excpt.what() << '\n';
    }
}


#endif