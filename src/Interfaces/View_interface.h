#ifndef VIEW_INTERFACE_H
#define VIEW_INTERFACE_H

#include <sstream>
#include <string>

class View_interface
{
	virtual std::string send_formatted(const std::string& account_name) const = 0;

	virtual std::ostringstream send_as_stream() const = 0;

	virtual void read_from_stream(std::istringstream& to_read) const = 0;
};

#endif
