compiler = g++
flags = -Wall -Werror -Wextra -Wpedantic -O3 -std=c++17 -g -o
accounts = src/Users_list.cpp src/Account.cpp src/User.cpp
misc = src/io.cpp src/Menu_manager.cpp
task = src/todolist.cpp src/task_list.cpp src/tasks.cpp 
cppfiles = $(accounts) $(misc) $(task)
program = todolist

install: 
	mkdir users && touch users/users.csv | echo essentials installed!!

build: 
	$(compiler) $(cppfiles) $(flags) $(program)

run:
	./todolist
