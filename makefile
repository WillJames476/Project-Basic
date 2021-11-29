compiler = g++
flags = -Wall -Werror -Wextra -Wpedantic -O3 -std=c++17 -I -g -o
accounts = src/Account/Users_list.cpp src/Account/Account.cpp src/Account/User.cpp src/Account/Communication_lines.cpp
misc = src/io.cpp src/Menu_manager.cpp

task = src/Todolist/todolist.cpp src/Todolist/task_list.cpp src/Todolist/tasks.cpp 
cppfiles = $(accounts) $(misc) $(task)
program = todolist

install: 
	mkdir users && touch users/users.csv | echo essentials installed!!

build: 
	$(compiler) $(cppfiles) $(flags) $(program)

run:
	./todolist
