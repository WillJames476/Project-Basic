#include <sstream>
#include <string>
#include <iostream>

#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/containers/string.hpp>

#include "../Utilities/io.h"
#include "Transmitter.h"

void transmit_data(const std::string& datas)
{
	using namespace boost::interprocess;

	try
	{
		shared_memory_object::remove("RADIO");
		managed_shared_memory sh_mem{create_only, "RADIO", 1024};
		sh_mem.construct<string>("DATA")(datas);
	}
	catch(interprocess_exception &except)
	{
		std::cerr << FEEDBACK_COLORS::BAD
				<< except.what()
			 	<< FEEDBACK_COLORS::RESET << '\n';
	}
}

std::array<std::string, 2> receive_data()
{
	using namespace boost::interprocess;
	std::array<std::string,2>string_to_return_arr
	{std::string{},std::string{}};
		
	try
	{
		managed_shared_memory sh_mem{open_only, "RADIO"};
		auto x = sh_mem.find<string>("DATA");
    	sh_mem.destroy<string>("DATA");

		std::stringstream buffer;
    	buffer << *x.first;
		buffer >> string_to_return_arr[0] >> string_to_return_arr[1];
	}
	catch(interprocess_exception &except)
	{
		std::cerr << FEEDBACK_COLORS::BAD 
					<< except.what()
					<< FEEDBACK_COLORS::RESET <<'\n';
	}

	return string_to_return_arr;
}
