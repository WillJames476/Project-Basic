#ifndef SERVER_CONTROL_H
#define SERVER_CONTROL_H

#include <string>
#include <agregates/control_agregate.h>
#include <agregates/view_agregate.h>

std::string
server_control(const std::string& message,
	       const Control_agregate& control,
	       const View_agregate& view);

#endif
