# Todolist
* A basic todolist app, with acount management
* disclaimer this program's account system does
  minimal security measures, it is highly recomended
  to use burner accounts

# Prerequisites
* c++20 compliant compiler
* unix-like systems / posix compliant systems

# Instalation
1. clone the repository
2. goto the directory of the repository 
3. type make install on your terminal
4. type make build on your terminal
5. enjoy

# Usage
1. open two terminal on the same directory where this repo is
2. lauch programs on the first terminal then launch you second program on the other terminal and vice versa
3. alternate between these terminal
4. press ctrl + z when you are done

# Uninstalling
1. delete the folder repo

# Applications on this repo
* Account manager (executable as ./account)
  - The account manager of the program
  - expects no inputs and outputs a user to be accesed by other files
  - can create and remove accounts

* Account communications manager (executable as ./commline)
  - a way to communicate with other accounts
  - can add / remove communication line between two users
  - a one way of communication
  - expects inputs from ./account and outpts a chosen communication line

* Task manager (executable as ./todolist)
  - todolist application of the repo
  - can add / remove tasks
  - expects inputs and produce output
  - other users can alter an account list as long as he/she has communication
    line to that user

* Chats (executable as ./chat)
  - can chat with other registered users of this program as long as you are
    have a verified communication line with the user you are trying to communicate with
  - can send and view messages
  - a expects input and can produce output