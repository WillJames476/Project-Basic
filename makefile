compiler = g++
flags = -Wall -Werror -Wextra -Wpedantic -O3 -g -o
cppfiles = src/todolist.cpp src/task_list.cpp src/tasks.cpp src/io.cpp src/accounts.cpp
program = todolist

install: 
	mkdir users && touch users/users.txt | echo essentials installed!!

build: 
	$(compiler) $(cppfiles) $(flags) $(program)
