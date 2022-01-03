compiler = g++
flags = -Wall -Werror -Wextra -Wpedantic -O3 -std=c++17 -I -g -o 

misc = src/Utilities/io.cpp src/Utilities/Transmitter.cpp src/loging/loger.cpp

accounts = src/Account/Users_list.cpp src/Account/Account.cpp 
accounts1 = src/Account/Acccount_menu.cpp src/Account/Main.cpp

com_lines = src/Account_Communicator/Main.cpp src/Account_Communicator/Communication_line_menu.cpp
com_lines1 = src/Account_Communicator/Communication_line.cpp

task = src/Todolist/Main.cpp src/Todolist/task_list.cpp src/Todolist/tasks.cpp src/Todolist/Todolist_menu.cpp

chat = src/Chat/Main.cpp src/Chat/Message_tuple.cpp src/Chat/Massge_list.cpp
chat1 = src/Chat/Message_menu.cpp

cbooks = src/ContactBook/Main.cpp src/ContactBook/Contacts_list.cpp src/ContactBook/Contacts_book_menu.cpp
cbooks1 = src/ContactBook/Contacts.cpp

exit = src/Exit/Main.cpp src/Exit/Exitui.cpp

account_program = account
task_program = todolist
commline_program = commline
chat_program = chat
exit_program = exit
contacts_program = cbook

build:
	make login && make task && make comm_lines && make conversation && make exiter && make contacts

install: 
	mkdir users && touch users/users.txt && mkdir tmp | echo essentials installed!!

uninstall:
	rm -rf users tmp account cbook chat comline exit src

login:
	$(compiler) $(accounts) $(accounts1) $(misc) $(flags) $(account_program) 

task: 
	$(compiler) $(task) $(misc) $(flags) $(task_program)

comm_lines:
	$(compiler) $(com_lines) $(com_lines1) $(misc) $(flags) $(commline_program)

conversation:
	$(compiler) $(chat) $(chat1) $(misc) $(flags) $(chat_program)

contacts:
	$(compiler) $(cbooks) $(cbooks1) $(misc) $(flags) $(contacts_program)

exiter:
	$(compiler) $(exit) $(misc) -lncurses $(flags) $(exit_program)
