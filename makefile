install: 
	mkdir users && touch users/users.txt | echo essentials installed!!

compile: src/todolist.cpp src/task_list.cpp src/tasks.cpp src/io.cpp src/accounts.cpp
	g++ src/todolist.cpp src/task_list.cpp src/tasks.cpp src/io.cpp src/accounts.cpp -o todolist -g
