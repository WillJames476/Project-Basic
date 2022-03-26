client_sources = ['main/Client_main.cpp']

executable('client',
	   sources : client_sources,
	   include_directories : input_output_hdr,
	   dependencies : [boost_dep,
			   thread_dep],
	   link_with : input_output_lib)

