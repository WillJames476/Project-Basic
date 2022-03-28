client_main_hdr = include_directories('main')

client_sources = ['main/Client_main.cpp',
		  'main/client_runtime.cpp']

executable('client',
	   sources : client_sources,
	   include_directories : [input_output_hdr,
				  client_main_hdr],
	   dependencies : [boost_dep,
			   thread_dep],
	   link_with : input_output_lib)


