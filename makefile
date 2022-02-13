CXX = g++
CXXFLAGS = -pipe -Wall -Werror -Wextra -Wpedantic -O3 -std=c++20 -I -g

BIN = bin
SRC = src
OBJ = obj
HDR = includes
Clean = clean
CLIENT = client

move_obj = mv *.o $(OBJ)

Utils = $(wildcard $(SRC)/Utilities/*.cpp)
Client_files = $(wildcard $(SRC)/Client/*.cpp)
Server_files = $(wildcard $(SRC)/Server/*.cpp)
Tester_files = $(wildcard $(SRC)/Tester/*.cpp)

Account_files = $(wildcard $(SRC)/Account/*.cpp)
Commline_files = $(wildcard $(SRC)/Commline/*.cpp)
Todolist_files = $(wildcard $(SRC)/Todolist/*.cpp)

Utils_obj = $(patsubst $(SRC)/Utilities/%.cpp, $(OBJ)/%.o, $(Utils))
Server_obj = $(patsubst $(SRC)/Server/%.cpp, $(OBJ)/%.o, $(Server_files))
Client_obj = $(patsubst $(SRC)/Client/%.cpp, $(OBJ)/%.o, $(Client_files))
Tester_obj = $(patsubst $(SRC)/Tester/%.cpp, $(OBJ)/%.o, $(Tester_files))

Account_obj = $(patsubst $(SRC)/Account/%.cpp, $(OBJ)/%.o, $(Account_files))
Commline_obj = $(patsubst $(SRC)/Commline/%.cpp, $(OBJ)/%.o, $(Commline_files))
Todolist_obj = $(patsubst $(SRC)/Todolist/%.cpp, $(OBJ)/%.o, $(Todolist_files))

Server_program = $(BIN)/server
Client_program = $(BIN)/client
Tester_program = $(BIN)/tester

define programs
	$(Server_program) \
	$(Client_program)
endef

all:
	make $(programs)

install: 
	mkdir users $(BIN) $(OBJ) && touch users/users.txt 

uninstall:
	rm -rf $(SRC) && $(Clean)

move_obj:
	$(shell mv *.o $(OBJ))

$(Clean):
	rm -rf $(BIN)/* $(OBJ)/*

$(Server_program): $(Server_obj) $(Utils_obj) $(Account_obj) $(Commline_obj) $(Todolist_obj)
	$(CXX) $^ -o $@

$(Client_program): $(Client_obj) $(Utils_obj) $(Account_obj) $(Commline_obj) $(Todolist_obj)
	$(CXX) $^ -o $@

$(Tester_program): $(Tester_obj) $(Todolist_obj)
	$(CXX) $^ -o $@

$(Utils_obj): $(Utils)
	$(CXX) $(CXXFLAGS) -I $(HDR) -c $^ && $(move_obj)

$(Server_obj): $(Server_files)
	$(CXX) $(CXXFLAGS) -I $(HDR) -c $^ && $(move_obj)

$(Client_obj): $(Client_files)
	$(CXX) $(CXXFLAGS) -I $(HDR) -c $^ && $(move_obj)

$(Tester_obj): $(Tester_files)
	$(CXX) $(CXXFLAGS) -I $(HDR) -c $^ && $(move_obj)

$(Account_obj): $(Account_files)
	$(CXX) $(CXXFLAGS) -I $(HDR) -c $^ && $(move_obj)

$(Commline_obj): $(Commline_files)
	$(CXX) $(CXXFLAGS) -I $(HDR) -c $^ && $(move_obj)

$(Todolist_obj): $(Todolist_files)
	$(CXX) $(CXXFLAGS) -I $(HDR) -c $^ && $(move_obj)