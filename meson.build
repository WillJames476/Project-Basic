project('Project-Tasker',
	'cpp',
	default_options : ['warning_level=3',
			   'optimization=3',
			   'debug=true',
			   'cpp_std=c++17'],
	version : '0.0',
	license : 'GPLV3')

boost_dep = dependency('boost')

thread_dep = dependency('threads')

commons = include_directories('inc')

commons_input_output = library('input_output',
			       sources : ['src/Utilities/io.cpp',
					  'src/Utilities/server_utilities.cpp'],
			       include_directories : commons)

subdir('src/Client')
subdir('src/Server')
