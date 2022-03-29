project('Project-Tasker',
	'cpp',
	default_options : ['warning_level=3',
			   'optimization=3',
			   'debug=true',
			   'cpp_std=c++17'],
	version : '0.0',
	license : 'GPL-3.0-or-later')

boost_dep = dependency('boost')

thread_dep = dependency('threads')

subdir('inc/')
subdir('src/Client')
subdir('src/Server')
