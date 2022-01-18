COMPILER = g++
FLAGS = -pipe -Wall -Werror -Wextra -Wpedantic -O3 -std=c++20 -I -g

BOOST = -lboost_program_options #-I #eneter your boost's absolute path here if needed#
BIN = bin
SRC = src
OBJ = obj
HDR = includes
Clean = clean
CLIENT = client

move_obj = mv *.o $(OBJ)

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
Account_obj = $(patsubst $(SRC)/Account/%.cpp, $(OBJ)/%.o , $(Account))
Comm_line_obj = $(patsubst $(SRC)/Account_Communicator/%.cpp, $(OBJ)/%.o, $(Comm_line))
Task_obj = $(patsubst $(SRC)/Todolist/%.cpp, $(OBJ)/%.o, $(Task))
Chat_obj = $(patsubst $(SRC)/Chat/%.cpp, $(OBJ)/%.o, $(Chat))
Cbook_obj = $(patsubst $(SRC)/ContactBook/%.cpp, $(OBJ)/%.o, $(Cbook))
Handler_obj = $(patsubst $(SRC)/ProgramsHandler/%.cpp, $(OBJ)/%.o, $(Handler))
Exit_obj = $(patsubst $(SRC)/Exit/%.cpp, $(OBJ)/%.o, $(Exit))

account_program = $(BIN)/account
task_program = $(BIN)/todolist
commline_program = $(BIN)/commline
chat_program = $(BIN)/chat
exit_program = $(BIN)/exit
contacts_program = $(BIN)/cbook
handler_program = $(BIN)/handler

programs = $(account_program) $(task_program) $(commline_program) $(chat_program) $(contacts_program) $(handler_program) $(exit_program)

$(account_program): $(Account_obj) $(Utils_obj) $(Log_obj)  
	$(COMPILER) $(BOOST) -I $(HDR) $^ $(FLAGS) -o $@

$(task_program): $(Task_obj) $(Utils_obj) $(Log_obj)
	$(COMPILER) $(BOOST) -I $(HDR) $^ $(FLAGS) -o $@

$(commline_program): $(Comm_line_obj) $(Utils_obj) $(Log_obj)
	$(COMPILER) $(BOOST) -I $(HDR) $^ $(FLAGS) -o $@

$(chat_program): $(Chat_obj) $(Utils_obj) $(Log_obj)
	$(COMPILER) $(BOOST) -I $(HDR) $^ $(FLAGS) -o $@

$(contacts_program): $(Cbook_obj) $(Utils_obj) $(Log_obj)
	$(COMPILER) $(BOOST) -I $(HDR) $^ $(FLAGS) -o $@

$(handler_program): $(Handler_obj) $(Utils_obj) $(Log_obj)
	$(COMPILER) $(BOOST) -I $(HDR) $^ $(FLAGS) -o $@

$(exit_program): $(Exit_obj) $(Utils_obj) $(Log_obj)
	$(COMPILER) $(BOOST) -I $(HDR) $^ $(FLAGS) -o $@

$(Utils_obj): $(Utils)
	$(COMPILER) -I $(HDR) -c $^ && $(move_obj)

$(Log_obj): $(Log)
	$(COMPILER) $(FLAGS) -I $(HDR) -c $< -o $@

$(Account_obj): $(Account)
	$(COMPILER) $(FLAGS) -I $(HDR) -c $^ && $(move_obj)

$(Comm_line_obj): $(Comm_line)
	$(COMPILER) $(FLAGS) -I $(HDR) -c $^ && $(move_obj)

$(Task_obj): $(Task)
	$(COMPILER) $(FLAGS) -I $(HDR) -c $^ && $(move_obj)

$(Chat_obj): $(Chat)
	$(COMPILER) $(FLAGS) -I $(HDR) -c $^ && $(move_obj)

$(Cbook_obj): $(Cbook)
	$(COMPILER) $(FLAGS) -I $(HDR) -c $^ && $(move_obj)

$(Handler_obj): $(Handler)
	$(COMPILER) $(FLAGS) -I $(HDR) -c $^ && $(move_obj)

$(Exit_obj): $(Exit)
	$(COMPILER) $(FLAGS) -I $(HDR) -c $^ && $(move_obj)

build:
	make $(programs)

install: 
	mkdir users $(BIN) $(OBJ) && touch users/users.txt 

uninstall:
	rm -rf $(Clean) $(SRC)

$(Clean):
	rm -rf $(BIN)/*