#include <string>
#include <sstream>

#include "model_agregate.h"
#include <server/control_agregate.h>
#include <server/view_agregate.h>
#include "file_agregates.h"
#include "server_control_utilities.h"

std::string server_control(const std::string& message,
			   const Control_agregate& control,
			   const View_agregate& view)
{
  std::istringstream method_extract(message);
  std::string method    {};
  std::string to_return {message};
  method_extract >> method;

  if(method == "GET")
    {
      to_return = get_control(method_extract, view, control);
    }
  else if(method == "POST")
    {
      to_return = post_control(method_extract, control);
    }
  else if(method == "DELETE")
    {
      to_return = delete_control(method_extract, control);
    }
  else if(method == "PUT")
    {
      to_return = put_control(method_extract, control);
    }
  else if(method == "END")
    {
      to_return = "END";
    }

  return to_return;
}
