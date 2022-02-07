CXX = g++
CXXFLAGS = -pipe -Wall -Werror -Wextra -Wpedantic -O3 -std=c++20 -I -g

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
Client_files = $(wildcard $(SRC)/Client/*.cpp)
Server_files = $(wildcard $(SRC)/Server/*.cpp)

Utils_obj = $(patsubst $(SRC)/Utilities/%.cpp, $(OBJ)/%.o, $(Utils))
Log_obj = $(patsubst $(SRC)/loging/%.cpp, $(OBJ)/%.o, $(Log))
Account_obj = $(patsubst $(SRC)/Account/%.cpp, $(OBJ)/%.o , $(Account))
Comm_line_obj = $(patsubst $(SRC)/Account_Communicator/%.cpp, $(OBJ)/%.o, $(Comm_line))
Task_obj = $(patsubst $(SRC)/Todolist/%.cpp, $(OBJ)/%.o, $(Task))
Chat_obj = $(patsubst $(SRC)/Chat/%.cpp, $(OBJ)/%.o, $(Chat))
Cbook_obj = $(patsubst $(SRC)/ContactBook/%.cpp, $(OBJ)/%.o, $(Cbook))
Handler_obj = $(patsubst $(SRC)/ProgramsHandler/%.cpp, $(OBJ)/%.o, $(Handler))
Exit_obj = $(patsubst $(SRC)/Exit/%.cpp, $(OBJ)/%.o, $(Exit))
Server_obj = $(patsubst $(SRC)/Server/%.cpp, $(OBJ)/%.o, $(Server_files))
Client_obj = $(patsubst $(SRC)/Client/%.cpp, $(OBJ)/%.o, $(Client_files))

account_program = $(BIN)/account
task_program = $(BIN)/todolist
commline_program = $(BIN)/commline
chat_program = $(BIN)/chat
exit_program = $(BIN)/exit
contacts_program = $(BIN)/cbook
handler_program = $(BIN)/handler
Server_program = $(BIN)/server
Client_program = $(BIN)/client

define programs
	$(account_program) \
	$(task_program) \
	$(commline_program) \
	$(chat_program) \
	$(contacts_program) \
	$(handler_program) \
	$(exit_program) \
	$(Server_program) \
	$(Client_program)
endef

all:
	make $(programs)

install: 
	mkdir users $(BIN) $(OBJ) && touch users/users.txt 

uninstall:
	rm -rf $(SRC) && $(Clean)

$(Clean):
	rm -rf $(BIN)/*

$(account_program): $(Account_obj) $(Utils_obj) $(Log_obj)  
	$(CXX) $(BOOST) -I $(HDR) $^ $(CXXFLAGS) -o $@

$(task_program): $(Task_obj) $(Utils_obj) $(Log_obj)
	$(CXX) $(BOOST) -I $(HDR) $^ $(CXXFLAGS) -o $@

$(commline_program): $(Comm_line_obj) $(Utils_obj) $(Log_obj)
	$(CXX) $(BOOST) -I $(HDR) $^ $(CXXFLAGS) -o $@

$(chat_program): $(Chat_obj) $(Utils_obj) $(Log_obj)
	$(CXX) $(BOOST) -I $(HDR) $^ $(CXXFLAGS) -o $@

$(contacts_program): $(Cbook_obj) $(Utils_obj) $(Log_obj)
	$(CXX) $(BOOST) -I $(HDR) $^ $(CXXFLAGS) -o $@

$(handler_program): $(Handler_obj) $(Utils_obj) $(Log_obj)
	$(CXX) $(BOOST) -I $(HDR) $^ $(CXXFLAGS) -o $@

$(exit_program): $(Exit_obj) $(Utils_obj) $(Log_obj)
	$(CXX) $(BOOST) -I $(HDR) $^ $(CXXFLAGS) -o $@

$(Server_program): $(Server_obj) $(Utils_obj)
	$(CXX) $(BOOST) -I $(HDR) $^ $(CXXFLAGS) -o $@

$(Client_program): $(Client_obj) $(Utils_obj)
	$(CXX) $(BOOST) -I $(HDR) $^ $(CXXFLAGS) -o $@

$(Utils_obj): $(Utils)
	$(CXX) -I $(HDR) -c $^ && $(move_obj)

$(Log_obj): $(Log)
	$(CXX) $(CXXFLAGS) -I $(HDR) -c $< -o $@

$(Account_obj): $(Account)
	$(CXX) $(CXXFLAGS) -I $(HDR) -c $^ && $(move_obj)

$(Comm_line_obj): $(Comm_line)
	$(CXX) $(CXXFLAGS) -I $(HDR) -c $^ && $(move_obj)

$(Task_obj): $(Task)
	$(CXX) $(CXXFLAGS) -I $(HDR) -c $^ && $(move_obj)

$(Chat_obj): $(Chat)
	$(CXX) $(CXXFLAGS) -I $(HDR) -c $^ && $(move_obj)

$(Cbook_obj): $(Cbook)
	$(CXX) $(CXXFLAGS) -I $(HDR) -c $^ && $(move_obj)

$(Handler_obj): $(Handler)
	$(CXX) $(CXXFLAGS) -I $(HDR) -c $^ && $(move_obj)

$(Exit_obj): $(Exit)
	$(CXX) $(CXXFLAGS) -I $(HDR) -c $^ && $(move_obj)

$(Server_obj): $(Server_files)
	$(CXX) $(CXXFLAGS) -I $(HDR) -c $^ && $(move_obj)

$(Client_obj): $(Client_files)
	$(CXX) $(CXXFLAGS) -I $(HDR) -c $^ && $(move_obj)