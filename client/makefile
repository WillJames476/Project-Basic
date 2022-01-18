COMPILER = g++
FLAGS = -pipe -Wall -Werror -Wextra -Wpedantic -O3 -std=c++20 -I -g -o

BOOST = -lboost_program_options #-I #eneter your boost's absolute path here if needed#
BIN = bin
SRC = src
OBJ = obj
HDR = includes
Clean = clean
CLIENT = client

Utils = $(wildcard $(SRC)/Utilities/*.cpp)
Log = $(wildcard $(SRC)/loging/*.cpp)
Account = $(wildcard $(SRC)/Account/*.cpp)
Comm_line = $(wildcard $(SRC)/Account_Communicator/*.cpp)
Task = $(wildcard $(SRC)/Todolist/*.cpp)
Chat = $(wildcard $(SRC)/Chat/*.cpp)
Cbook = $(wildcard $(SRC)/ContactBook/*.cpp)
Handler = $(wildcard $(SRC)/ProgramsHandler/*.cpp)
Exit = $(wildcard $(SRC)/Exit/*.cpp)

Utils_obj = $(patsubst $(SRC)/Utilities/%.cpp, $(OBJ)/%.o, $(Utils))
Log_obj = $(patsubst $(SRC)/loging/%.cpp, $(OBJ)/%.o, $(Log))

account_program = $(BIN)/account
task_program = $(BIN)/todolist
commline_program = $(BIN)/commline
chat_program = $(BIN)/chat
exit_program = $(BIN)/exit
contacts_program = $(BIN)/cbook
handler_program = $(BIN)/handler

programs = $(account_program) $(task_program) $(commline_program) $(chat_program) $(contacts_program) $(handler_program) $(exit_program)

$(account_program): $(Account) $(Utils_obj) $(Log_obj)  
	$(COMPILER) $(BOOST) -I $(HDR) $^ $(FLAGS) $@

$(task_program): $(Task) $(Utils_obj) $(Log_obj)
	$(COMPILER) $(BOOST) -I $(HDR) $^ $(FLAGS) $@

$(commline_program): $(Comm_line) $(Utils_obj) $(Log_obj)
	$(COMPILER) $(BOOST) -I $(HDR) $^ $(FLAGS) $@

$(chat_program): $(Chat) $(Utils_obj) $(Log_obj)
	$(COMPILER) $(BOOST) -I $(HDR) $^ $(FLAGS) $@

$(contacts_program): $(Cbook) $(Utils_obj) $(Log_obj)
	$(COMPILER) $(BOOST) -I $(HDR) $^ $(FLAGS) $@

$(handler_program): $(Handler) $(Utils_obj) $(Log_obj)
	$(COMPILER) $(BOOST) -I $(HDR) $^ $(FLAGS) $@

$(exit_program): $(Exit) $(Utils_obj) $(Log_obj)
	$(COMPILER) $(BOOST) -I $(HDR) $^ $(FLAGS) $@

$(Utils_obj): $(Utils)
	$(COMPILER) -I $(HDR) -c $^ && mv *.o obj

$(Log_obj): $(Log)
	$(COMPILER) -I $(HDR) -c $< -o $@

build:
	make $(programs)

install: 
	mkdir users $(BIN) $(OBJ) && touch users/users.txt 

uninstall:
	rm -rf $(Clean) $(SRC)

$(Clean):
	rm -rf $(BIN)/*