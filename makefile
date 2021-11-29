compiler = g++
flags = -Wall -Werror -Wextra -Wpedantic -O3 -std=c++17 -I -g -o
accounts = src/Account/Users_list.cpp src/Account/Account.cpp src/Account/User.cpp src/Account/Communication_lines.cpp src/Account/Acccount_menu.cpp
misc = src/Utilities/io.cpp 
task = src/Todolist/todolist.cpp src/Todolist/task_list.cpp src/Todolist/tasks.cpp src/Todolist/Todolist_menu.cpp
cppfiles = $(accounts) $(misc) $(task)
program = todolist

install: 
	mkdir users && touch users/users.csv | echo essentials installed!!

build: 
	$(compiler) $(cppfiles) $(flags) $(program)

run:
	./todolist
