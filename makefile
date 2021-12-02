compiler = g++
flags = -Wall -Werror -Wextra -Wpedantic -O3 -std=c++17 -I -g -o

misc = src/Utilities/io.cpp src/Utilities/Transmitter.cpp

accounts = src/Account/Users_list.cpp src/Account/Account.cpp 
accounts1 = src/Account/Acccount_menu.cpp src/Account/Main.cpp

com_lines = src/Account_Communicator/Main.cpp src/Account_Communicator/Communication_line_menu.cpp
com_lines1 = src/Account_Communicator/Communication_line.cpp
task = src/Todolist/Main.cpp src/Todolist/task_list.cpp src/Todolist/tasks.cpp src/Todolist/Todolist_menu.cpp

account_program = account
task_program = todolist
commline_program = commline

install: 
	mkdir users && touch users/users.csv && mkdir tmp | echo essentials installed!!

login:
	$(compiler) $(accounts) $(accounts1) $(misc) $(flags) $(account_program) 

task: 
	$(compiler) $(task) $(misc) $(flags) $(task_program)

comm_lines:
	$(compiler) $(com_lines) $(com_lines1) $(misc) $(flags) $(commline_program)