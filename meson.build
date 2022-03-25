project('Project-Tasker',
	'cpp',
	default_options : ['cpp_std=c++17'],
	version : '0.0',
	license : 'GPLV3')

boost_dep = dependency('boost')

thread_dep = dependency('threads')

commons = include_directories('inc')

commons_input_output = library('input_output',
			       ['src/Utilities/io.cpp',
				'src/Utilities/server_utilities.cpp'],
			       include_directories : commons)

subdir('src/Client')
subdir('src/Server')
