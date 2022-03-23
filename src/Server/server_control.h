#ifndef SERVER_CONTROL_H
#define SERVER_CONTROL_H

#include <string>
#include <server/control_agregate.h>
#include <server/view_agregate.h>

std::string server_control(const std::string& message,
			   const Control_agregate& control,
			   const View_agregate& view);
#endif
