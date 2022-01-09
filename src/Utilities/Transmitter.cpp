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
		managed_shared_memory sh_mem{open_or_create, "RADIO", 1024};
		sh_mem.construct<string>("DATA")(datas);
	}
	catch(bad_alloc &x)
	{
		std::cerr << FEEDBACK_COLORS::BAD << x.what()
					<< FEEDBACK_COLORS::RESET << '\n';
	}
}

std::array<std::string, 2> receive_data()
{
	using namespace boost::interprocess;
	managed_shared_memory sh_mem{open_or_create, "RADIO", 1024};
	auto x = sh_mem.find<string>("DATA");
    sh_mem.destroy<string>("DATA");

	std::stringstream buffer;
    buffer << *x.first;
	std::array<std::string, 2 >string_to_return_arr;
	buffer >> string_to_return_arr[0] >> string_to_return_arr[1];

	return string_to_return_arr;
}
