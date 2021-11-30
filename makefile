compiler = g++
flags = -Wall -Werror -Wextra -Wpedantic -O3 -std=c++17 -I -g -o

accounts = src/Account/Users_list.cpp src/Account/Account.cpp 
accounts1 = src/Account/User.cpp src/Account/Communication_lines.cpp 
accounts2 = src/Account/Acccount_menu.cpp src/Account/Main.cpp

misc = src/Utilities/io.cpp src/Utilities/Transmitter.cpp

task = src/Todolist/Main.cpp src/Todolist/task_list.cpp src/Todolist/tasks.cpp src/Todolist/Todolist_menu.cpp

account_program = account
task_program = todolist

install: 
	mkdir users && touch users/users.csv && mkdir tmp | echo essentials installed!!

login:
	$(compiler) $(accounts) $(accounts1) $(accounts2) $(misc) $(flags) $(account_program) 

task: 
	$(compiler) $(task) $(misc) $(flags) $(task_program)
