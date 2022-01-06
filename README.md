# Project Basic
* A basic set of applicatons.
* disclaimer this program's account system does
  minimal security measures, it is highly recomended
  to use burner accounts

# Prerequisites
* c++20 compliant compiler
* up to date boostc++ library
* ncurses

# Instalation
1. clone the repository
2. goto the directory of the repository
3. enter the absolute path of boost library from your pc to the specified
   comment on the makefile 
4. type make install on your terminal
5. type make build on your terminal
6. enjoy

# Usage
1. type ./handler on the terminal and launch applications when asked by prompt

# Uninstalling
1. type make uninstall on the terminal

# Applications on this repo
* Handler (executable as ./handler)
  - streamlines the process of using the applications
  - expects no inputs and yields no outputs
  - type an executable on it to excute a program

* Account manager (executable to handler as /account)
  - The account manager of the program
  - expects no inputs and outputs a user to be accesed by other files
  - can create and remove accounts

* Account communications manager (executable to handler as /commline)
  - a way to communicate with other accounts
  - can add / remove communication line between two users
  - a one way of communication
  - expects inputs from ./account and outpts a chosen communication line

* Task manager (executable to handler as /todolist)
  - todolist application of the repo
  - can add / remove tasks
  - expects inputs and produce output
  - other users can alter an account list as long as he/she has communication
    line to that user

* Chats (executable to handler as /chat)
  - can chat with other registered users of this program as long as you are
    have a verified communication line with the user you are trying to communicate with
  - can send and view messages
  - a expects input and can produce output

* Contacts book (executable to handler as /cbook)
  - can add and remove a contact info of a user has as long as you are permitted
  - view the contacts that a user has
  - expects input and can produce output
  
* Exit (executable to handler as /exit)
  - exits the program gracefully
  - removes pipes
  - only receives input
  - logs the users to a file
