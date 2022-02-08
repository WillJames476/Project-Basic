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
Client_files = $(wildcard $(SRC)/Client/*.cpp)
Server_files = $(wildcard $(SRC)/Server/*.cpp)
Tester_files = $(wildcard $(SRC)/Tester/*.cpp)

Utils_obj = $(patsubst $(SRC)/Utilities/%.cpp, $(OBJ)/%.o, $(Utils))
Server_obj = $(patsubst $(SRC)/Server/%.cpp, $(OBJ)/%.o, $(Server_files))
Client_obj = $(patsubst $(SRC)/Client/%.cpp, $(OBJ)/%.o, $(Client_files))
Tester_obj = $(patsubst $(SRC)/Tester/%.cpp, $(OBJ)/%.o, $(Tester_files))

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

$(Server_program): $(Server_obj) $(Utils_obj)
	$(CXX) $(BOOST) $^ -o $@

$(Client_program): $(Client_obj) $(Utils_obj)
	$(CXX) $(BOOST) $^ -o $@

$(Tester_program): $(Tester_obj) $(Server_obj)
	$(CXX) $(BOOST) $^ -o $@

$(Utils_obj): $(Utils)
	$(CXX) $(BOOST) $(CXXFLAGS) -I $(HDR) -c $^ && $(move_obj)

$(Server_obj): $(Server_files)
	$(CXX) $(BOOST) $(CXXFLAGS) -I $(HDR) -c $^ && $(move_obj)

$(Client_obj): $(Client_files)
	$(CXX) $(BOOST) $(CXXFLAGS) -I $(HDR) -c $^ && $(move_obj)

$(Tester_obj): $(Tester_files)
	$(CXX) $(BOOST) $(CXXFLAGS) -I $(HDR) -c $^ && $(move_obj)