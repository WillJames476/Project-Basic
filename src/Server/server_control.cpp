#include <string>
#include <sstream>

#include "model_agregate.h"
#include "control_agregate.h"
#include "file_agregates.h"
#include "server_control_utilities.h"

std::string server_control(const std::string& message)
{
    Model_agregate models{};
    Control_agregate controls{models};
    File_agregate files{models};
    file_control("READ", files);

    std::istringstream method_extract(message);
    std::string method{}, to_return{message};
    method_extract >> method;

    if(method == "GET")
    {
        to_return = get_control(method_extract, controls);
    }
    else if(method == "PUT")
    {
        to_return = put_control(method_extract, controls);
    }
    else if(method == "DELETE")
    {
        to_return = delete_control(method_extract, controls);
    }

    file_control("WRITE", files);

    return to_return;
}