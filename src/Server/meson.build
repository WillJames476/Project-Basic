account_hdr = include_directories('account')

commline_hdr = include_directories('commline')

account_sources = ['account/account_control.cpp',
		   'account/account_model.cpp',
		   'account/Account_view.cpp']

commline_sources = ['commline/Commline_model.cpp',
		    'commline/Commline_control.cpp',
		    'commline/Commline_view.cpp',
		    'commline/Permission_table.cpp']

account_lib = library('account',
		      sources : account_sources,
		      include_directories : account_hdr)

commline_lib = library('commline',
		       sources : commline_sources,
		       include_directories : commline_hdr)

todolist_lib = library('todolist')

