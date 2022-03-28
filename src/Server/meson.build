account_hdr = include_directories('account')

commline_hdr = include_directories('commline')

todolist_hdr = include_directories('todolist')

interfaces_hdr = include_directories('interfaces')

operations_hdr = include_directories('operations')

agregates_hdr = include_directories('agregates')

server_main_hdr = include_directories('main')

account_sources = ['account/account_control.cpp',
		   'account/account_model.cpp',
		   'account/Account_view.cpp']

commline_sources = ['commline/Commline_model.cpp',
		    'commline/Commline_control.cpp',
		    'commline/Commline_view.cpp',
		    'commline/Permission_table.cpp']

todolist_sources = ['todolist/Task.cpp',
		    'todolist/Todolist_model.cpp',
		    'todolist/Todolist_control.cpp',
		    'todolist/Todolist_view.cpp']

operation_sources = ['operations/delete_operations.cpp',
		     'operations/get_operations.cpp',
		     'operations/post_operations.cpp',
		     'operations/put_operations.cpp']

agregates_sources = ['agregates/model_agregate.cpp',
		     'agregates/control_agregate.cpp',
		     'agregates/file_agregate.cpp',
		     'agregates/view_agregate.cpp']

server_main_sources = ['main/server_control.cpp',
		       'main/server_control_utilities.cpp',
		       'main/server_main.cpp',
		       'main/server_runtime.cpp']

account_lib = library('account',
		      sources : account_sources,
		      include_directories : [account_hdr,
					    interfaces_hdr])

commline_lib = library('commline',
		       sources : commline_sources,
		       include_directories : [commline_hdr,
					     interfaces_hdr])

todolist_lib = library('todolist',
		       sources : todolist_sources,
		       include_directories : [todolist_hdr,
					      interfaces_hdr])

agregates_lib = library('agregates',
			sources : agregates_sources,
			include_directories : [input_output_hdr,
					       account_hdr,
					       commline_hdr,
					       todolist_hdr,
					       interfaces_hdr,
					       agregates_hdr],
			link_with : [account_lib,
				     todolist_lib,
				     commline_lib,
				     input_output_lib])

operations_lib = library('operations',
			 sources : operation_sources,
			 include_directories : [agregates_hdr,
						input_output_hdr,
						account_hdr,
						commline_hdr,
						todolist_hdr],
			 link_with : [agregates_lib,
				      input_output_lib,
				      account_lib,
				      commline_lib,
				      todolist_lib])

executable('server',
	   sources : server_main_sources,
	   include_directories : [input_output_hdr,
				  server_main_hdr,
				  agregates_hdr,
				  account_hdr,
				  commline_hdr,
				  todolist_hdr,
				  operations_hdr],
	   link_with : [agregates_lib,
			input_output_lib,
			account_lib,
			commline_lib,
			todolist_lib,
			operations_lib],
	   dependencies : [thread_dep,
			   boost_dep])



