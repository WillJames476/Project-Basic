CXX = g++
CXXFLAGS = -lpthread -pipe -Wall -Werror -Wextra -Wpedantic -O3 -std=c++20 -g -I

LDFLAGS = -pthread -o

BIN = bin
SRC = src
OBJ = obj
HDR = includes

move_obj = mv *.o $(OBJ)

Utils = $(wildcard $(SRC)/Utilities/*.cpp)
Client_files = $(wildcard $(SRC)/Client/*.cpp)
Server_files = $(wildcard $(SRC)/Server/*.cpp)
Tester_files = $(wildcard $(SRC)/Tester/*.cpp)

Account_files = $(wildcard $(SRC)/Account/*.cpp)
Commline_files = $(wildcard $(SRC)/Commline/*.cpp)
Todolist_files = $(wildcard $(SRC)/Todolist/*.cpp)
Operations_files = $(wildcard $(SRC)/Operations/*.cpp)

Utils_obj = $(patsubst $(SRC)/Utilities/%.cpp, $(OBJ)/%.o, $(Utils))
Server_obj = $(patsubst $(SRC)/Server/%.cpp, $(OBJ)/%.o, $(Server_files))
Client_obj = $(patsubst $(SRC)/Client/%.cpp, $(OBJ)/%.o, $(Client_files))
Tester_obj = $(patsubst $(SRC)/Tester/%.cpp, $(OBJ)/%.o, $(Tester_files))

Account_obj = $(patsubst $(SRC)/Account/%.cpp, $(OBJ)/%.o, $(Account_files))
Commline_obj = $(patsubst $(SRC)/Commline/%.cpp, $(OBJ)/%.o, $(Commline_files))
Todolist_obj = $(patsubst $(SRC)/Todolist/%.cpp, $(OBJ)/%.o, $(Todolist_files))
Operations_obj = $(patsubst $(SRC)/Operations/%.cpp, $(OBJ)/%.o, $(Operations_files))

Server_program = $(BIN)/server
Client_program = $(BIN)/client

define programs
	$(Server_program) \
	$(Client_program)
endef

all:
	make $(programs)

install:
	mkdir $(BIN) $(OBJ) data

uninstall:
	rm -rf $(SRC) && $(Clean)

dist:
	$(shell tar -zcf Project-Basic.tar.gz *)

move_obj:
	$(shell mv *.o $(OBJ))

clean:
	rm -rf $(BIN)/* $(OBJ)/*

$(Server_program): $(Server_obj) $(Utils_obj) $(Account_obj) $(Commline_obj) $(Todolist_obj) $(Operations_obj)
	$(CXX) $^ $(LDFLAGS) $@

$(Client_program): $(Client_obj) $(Utils_obj) $(Account_obj) $(Commline_obj) $(Todolist_obj)
	$(CXX) $^ $(LDFLAGS) $@

$(Utils_obj): $(Utils)
	$(CXX) $(CXXFLAGS) $(HDR) -c $^ && $(move_obj)

$(Server_obj): $(Server_files)
	$(CXX) $(CXXFLAGS) $(HDR) -c $^ && $(move_obj)

$(Client_obj): $(Client_files)
	$(CXX) $(CXXFLAGS) $(HDR) -c $^ && $(move_obj)

$(Tester_obj): $(Tester_files)
	$(CXX) $(CXXFLAGS) $(HDR) -c $^ && $(move_obj)

$(Account_obj): $(Account_files)
	$(CXX) $(CXXFLAGS) $(HDR) -c $^ && $(move_obj)

$(Commline_obj): $(Commline_files)
	$(CXX) $(CXXFLAGS) $(HDR) -c $^ && $(move_obj)

$(Todolist_obj): $(Todolist_files)
	$(CXX) $(CXXFLAGS) $(HDR) -c $^ && $(move_obj)

$(Operations_obj): $(Operations_files)
	$(CXX) $(CXXFLAGS) $(HDR) -c $^ && $(move_obj)
