COMPILER = g++
FLAGS = -pipe -Wall -Werror -Wextra -Wpedantic -O3 -std=c++20 -I -g -o

BOOST = -I #your boost path here#
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

handlers = src/ProgramsHandler/main.cpp src/ProgramsHandler/handler_ui.cpp

exit = src/Exit/Main.cpp src/Exit/Exitui.cpp

account_program = bin/account
task_program = bin/todolist
commline_program = bin/commline
chat_program = bin/chat
exit_program = bin/exit
contacts_program = bin/cbook
handler_program = handler

build:
	make login && make task && make comm_lines && make conversation && make exiter && make contacts && make handle

install: 
	mkdir users bin && touch users/users.txt && mkdir tmp && cd tmp && mkfifo cows && echo "NIL" > cows &| echo essentials installed!!

uninstall:
	rm -rf users tmp account cbook chat comline exit src

login:
	$(COMPILER) $(BOOST) $(accounts) $(accounts1) $(misc) $(FLAGS) $(account_program) 

task: 
	$(COMPILER) $(task) $(misc) $(FLAGS) $(task_program)

comm_lines:
	$(COMPILER) $(com_lines) $(com_lines1) $(misc) $(FLAGS) $(commline_program)

conversation:
	$(COMPILER) $(chat) $(chat1) $(misc) $(FLAGS) $(chat_program)

contacts:
	$(COMPILER) $(cbooks) $(cbooks1) $(misc) $(FLAGS) $(contacts_program)

handle:
	$(COMPILER) $(handlers) $(misc) $(FLAGS) $(handler_program)

exiter:
	$(COMPILER) $(exit) $(misc) -lncurses $(FLAGS) $(exit_program)
