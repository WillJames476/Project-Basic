#ifndef GENERIC_FILE
#define GENERIC_FILE

#include <fstream>
#include <string>
#include <memory>
#include <iostream>

template <typename T>
struct Generic_file
{
public:

  Generic_file(const T& viewer_object,
	       const std::string& file_target);

  void
  read_file() const;

  void
  save_file() const;

private:

  std::shared_ptr<T> viewer;
  
  std::string file_target_str;

};

template<typename T>
Generic_file<T>::Generic_file(const T& viewer_object
			      , const std::string& file_target)
  : viewer{std::make_shared<T>(viewer_object)}
  , file_target_str{file_target}
{
}

template <typename T>
void
Generic_file<T>::read_file() const
{
  try
    {
      std::ifstream file_to_read{file_target_str};

      viewer->read_from_stream(file_to_read);
      file_to_read.close();
    }
  catch(const std::exception& excpt)
    {
      std::cerr << excpt.what() << '\n';
    }
}

template <typename T>
void
Generic_file<T>::save_file() const
{
  try
    {
      std::ofstream file_to_save {file_target_str};

      file_to_save << viewer->send_as_stream().str();
      file_to_save.close();
    }
  catch(const std::exception& excpt)
    {
      std::cerr <<  excpt.what() << '\n';
    }
}

#endif
