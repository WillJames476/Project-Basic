#include <sstream>
#include <vector>

#include <agregates/view_agregate.h>
#include <agregates/file_agregate.h>
#include "server_control_utilities.h"

#include <operations/post_operations.h>
#include <operations/delete_operations.h>
#include <operations/get_operations.h>
#include <operations/put_operations.h>

namespace ARGS_REGEX
{
  using namespace REGEX_PREDICATES;

  std::initializer_list<std::regex>
  ACCOUNT        {ALPHA_NOSPACE, ALPHA_NOSPACE},
    COMMLINE     {ALPHA_NOSPACE, ALPHA_NOSPACE, ALPHA_NOSPACE},
    COMMLINE_PUT {ALPHA_NOSPACE, ALPHA_NOSPACE, ALPHA_NOSPACE, BOOLEAN},
    TASK         {ALPHA_NOSPACE, ALPHA_NOSPACE, ALPHA_NOSPACE, ALPHA_NOSPACE_S};
}

std::vector<std::string> extract_args(std::istringstream& message)
{
  std::vector<std::string> to_return;
  std::string holder{};

  while(message >> holder)
    {
      to_return.push_back(holder);
    }

  return to_return;
}

std::string get_control(std::istringstream& message,
			const View_agregate& view,
			const Control_agregate& control)
{
  std::string application{};
  message >> application;
  auto args{extract_args(message)};

  if(application == "--account")
    {
      application = apply_function(application, args,
				   ARGS_REGEX::ACCOUNT,
				   2, view,
				   [&](const auto& x, const auto& y)
				   {return get_account_info(x, control, y);});
    }
  else if(application == "--commline")
    {
      application = apply_function(application, args,
				   ARGS_REGEX::ACCOUNT,
				   2 , view,
				   [&](const auto& x, const auto& y)
				   {return get_commline_table(x, control,y);});
    }
  else if(application == "--todolist")
    {
      application = apply_function(application, args,
				   ARGS_REGEX::ACCOUNT,
				   2 , view,
				   [&](const auto& x, const auto& y)
				   {return get_todolist_list(x, control,y);});
    }

    return application;
}

std::string post_control(std::istringstream& message
                        , const Control_agregate& controls)
{
  std::string application{};
  message >> application;
  auto args{extract_args(message)};

  if(application == "--account")
    {
      application = apply_function(application, args,
				   ARGS_REGEX::ACCOUNT,
				   2, controls ,
				   [](const auto& x, const auto& y)
				   {return add_new_account(x, y);});
    }
  else if(application == "--commline")
    {
      application = apply_function(application, args,
				   ARGS_REGEX::COMMLINE,
				   3 ,controls,
				   [](const auto& x, const auto& y)
				   {return add_new_commline(x, y);});
    }
  else if(application == "--todolist")
    {
      application = apply_function(application,args,
				   ARGS_REGEX::TASK,
				   4, controls,
				   [](const auto& x, const auto& y)
				   {return add_new_task(x, y);});
    }

  return application;
}

std::string delete_control(std::istringstream& message
                        , const Control_agregate& controls)
{
  std::string application{};
  message >> application;
  auto args{extract_args(message)};

  if(application == "--account")
    {
      application = apply_function(application, args,
				   ARGS_REGEX::ACCOUNT,
				   2, controls ,
				   [](const auto& x, const auto& y)
				   {return delete_account(x, y);});
    }
  else if(application == "--commline")
    {
      application = apply_function(application, args,
				   ARGS_REGEX::COMMLINE,
				   3 ,controls,
				   [](const auto& x, const auto& y)
				   {return delete_a_line(x, y);});
    }
  else if(application == "--todolist")
    {
      application = apply_function(application, args,
				   ARGS_REGEX::TASK,
				   4, controls
				   , [](const auto& x, const auto& y)
				   {return delete_a_task(x, y);});
    }

  return application;
}

std::string put_control(std::istringstream& message
                        , const Control_agregate& controls)
{
  std::string application{};
  message >> application;
  auto args{extract_args(message)};

  if(application == "--commline")
    {
      application = apply_function(application, args,
				   ARGS_REGEX::COMMLINE_PUT,
				   4, controls,
				   [](const auto& x, const auto& y)
				   {return change_commline_permission(x, y);});
    }

  return application;
}

void file_control(const std::string& mode
                , File_agregate& file)
{
  if(mode == "READ")
    {
      file.read_all();
    }
  else if(mode == "WRITE")
    {
      file.save_all();
    }
}

