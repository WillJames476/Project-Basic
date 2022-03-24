CXX = g++
CXXFLAGS = -lpthread -pipe -Wall -Werror -Wextra -Wpedantic -O3 -std=c++20 -g -I

LDFLAGS = -lpthread -o

BINDIR = bin
SRCDIR = src
OBJDIR = obj
HDR = inc

move_obj = mv *.o $(OBJDIR)

Utils = $(wildcard $(SRCDIR)/Utilities/*.cpp)

Client_files = $(wildcard $(SRCDIR)/Client/*.cpp)
Server_files = $(wildcard $(SRCDIR)/Server/*.cpp)
Tester_files = $(wildcard $(SRCDIR)/Tester/*.cpp)

Account_files = $(wildcard $(SRCDIR)/Account/*.cpp)
Commline_files = $(wildcard $(SRCDIR)/Commline/*.cpp)
Todolist_files = $(wildcard $(SRCDIR)/Todolist/*.cpp)
Operations_files = $(wildcard $(SRCDIR)/Operations/*.cpp)

Utils_obj = $(patsubst $(SRCDIR)/Utilities/%.cpp, $(OBJDIR)/%.o, $(Utils))
Server_obj = $(patsubst $(SRCDIR)/Server/%.cpp, $(OBJDIR)/%.o, $(Server_files))
Client_obj = $(patsubst $(SRCDIR)/Client/%.cpp, $(OBJDIR)/%.o, $(Client_files))
Tester_obj = $(patsubst $(SRCDIR)/Tester/%.cpp, $(OBJDIR)/%.o, $(Tester_files))

Account_obj = $(patsubst $(SRCDIR)/Account/%.cpp, $(OBJDIR)/%.o, $(Account_files))
Commline_obj = $(patsubst $(SRCDIR)/Commline/%.cpp, $(OBJDIR)/%.o, $(Commline_files))
Todolist_obj = $(patsubst $(SRCDIR)/Todolist/%.cpp, $(OBJDIR)/%.o, $(Todolist_files))
Operations_obj = $(patsubst $(SRCDIR)/Operations/%.cpp, $(OBJDIR)/%.o, $(Operations_files))

Server_program = $(BINDIR)/server
Client_program = $(BINDIR)/client

define programs
	$(Server_program) \
	$(Client_program)
endef

all:
	make $(programs)

install:
	mkdir $(BINDIR) $(OBJDIR) data

uninstall:
	rm -rf $(SRCDIR) && $(Clean)

dist:
	$(shell tar -zcf Project-Basic.tar.gz *)

move_obj:
	$(shell mv *.o $(OBJDIR))

clean:
	rm -rf $(BINDIR)/* $(OBJDIR)/*

$(Server_program): $(Server_obj) $(Utils_obj) $(Account_obj) $(Commline_obj) $(Todolist_obj) $(Operations_obj)
	$(CXX) $^ $(LDFLAGS) $@

$(Client_program): $(Client_obj) $(Utils_obj) $(Account_obj) $(Commline_obj) $(Todolist_obj)
	$(CXX) $^ $(LDFLAGS) $@

$(Utils_obj): $(Utils)
	$(CXX) $(CXXFLAGS) $(HDR) -c $^ && $(move_obj)

$(Util_input_ouput_obj): $(Util_input_output_file)
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
