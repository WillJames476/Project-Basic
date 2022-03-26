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
			sources : ['agregates/model_agregate.cpp',
				   'agregates/control_agregate.cpp',
				   'agregates/file_agregate.cpp',
				   'agregates/view_agregate.cpp'],
			include_directories : [commons,
					       account_hdr,
					       commline_hdr,
					       todolist_hdr,
					       interfaces_hdr,
					       agregates_hdr],
			link_with : [account_lib,
				     todolist_lib,
				     commline_lib])

