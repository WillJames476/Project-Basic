#ifndef SERVER_CONTROL_H
#define SERVER_CONTROL_H

#include <string>

#include "control_agregate.h"
#include "view_agregate.h"

std::string server_control(const std::string& message,
			   const Control_agregate& control,
			   const View_agregate& view);
#endif
