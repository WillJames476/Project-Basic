#ifndef SERVER_CONTROL_UTILITIES_H
#define SERVER_CONTROL_UTILITIES_H

#include <sstream>
#include <vector>
#include "control_agregate.h"
#include "file_agregates.h"

std::string get_control(std::istringstream& message
                , const Control_agregate& controls);

std::string put_control(std::istringstream& message
                    , const Control_agregate& controls);

std::string delete_control(std::istringstream& message
                    , const Control_agregate& controls);

void file_control(const std::string& mode
                , File_agregate& file);

std::string apply_function(const std::vector<std::string>& list
                        , size_t expected_size
                        , const Control_agregate& controls
                        , std::string(*applier)
                            (const Control_agregate& ,const std::vector<std::string>&));


#endif
