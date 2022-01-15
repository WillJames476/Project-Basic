# Project Basic
* A basic set of applicatons.
* disclaimer this program's account system does
  minimal security measures, it is highly recomended
  to use burner accounts

# Prerequisites
* c++20 compliant compiler

# Third party libraries used
* This software includes third party open source software they are: 
1. Boost c++ library
  * the Boost c++ library have their own license. Please see:
    Boost/LICENSE, https://github.com/boostorg/boost.git or www.boost.org

# Instalation
1. clone the repository
2. goto the directory of the repository,
   optional. enter the absolute path of boost library from your pc to the specified
   comment on the makefile 
3. type make install on your terminal
4. type make build on your terminal
5. enjoy

# Usage
1. type bin/handler on the terminal and launch applications when asked by prompt

# Uninstalling
1. type make uninstall on the terminal

# Applications on this repo
* Handler (executable as bin/handler)
  - streamlines the process of using the applications
  - expects no inputs and yields no outputs
  - type an executable on it to excute a program

* Account manager (executable to handler as /account)
  - The account manager of the program
  - expects no inputs and outputs a user to be accesed by other files
  - can create and remove accounts

  * available commands
    - --help   [no-args]           shows all available commands
    - --login  [string1, string2]  access an account to list      (username, password)
    - --create [string1, string2]  adds a account to list         (username, password)
    - --delete [string1, string2]  deletes an account to the list (username, password)

* Account communications manager (executable to handler as /commline)
  - a way to communicate with other accounts
  - can add / remove communication line between two users
  - a one way of communication
  - expects an input

  * availabale commands
  - --help   [no-args] shows all availaba commands
  - --add    [string1] adds a user to the communication line           (username)
  - --delete [string1] deletes a user the the communication line       (username)
  - --alter  [string1] grants/revokes premission of other users to you (username)
  - --view   [no-args] view the user's communication line  
  - --access [string1] acces a user                                    (username)

* Task manager (executable to handler as /todolist)
  - todolist application of the repo
  - can add / remove tasks
  - expects inputs and produce output
  - other users can alter an account list as long as he/she has communication
    line to that user
  
  * availabale commands
  - --help [no-args] shows all availaba commands
  - --add [string1, string2, string,3 string4] adds a task to the list (task name, task month, task date,         date     increment)
  - --delete [string1] deletes all task of the gien name (task name)
  - --deletesp [string1, string2,string3] delete task of given name, date, and month (task name, task month, task date)
  - --view [no-args] view the user's task list      

* Chats (executable to handler as /chat)
  - can chat with other registered users of this program as long as you are
    have a verified communication line with the user you are trying to communicate with
  - can send and view messages
  - a expects input and can produce output
  
  * availabale commands
  - --help   [no-args] shows all availaba commands
  - --add    [string1] adds a user to the communication line (username, message)
  - --view   [no-args] view the user's communication line  

* Contacts book (executable to handler as /cbook)
  - can add and remove a contact info of a user has as long as you are permitted
  - view the contacts that a user has
  - expects input and can produce output
  * availabale commands
  - --help   [no-args] shows all availaba commands
  - --add    [string1,string2m string3] adds a user to the communication line           (name, number,email)
  - --remove [string1,string2, string3] deletes a contact from list (name, number email)
  - --view   [no-args] view the user's communication line  
  - --search [string1, string 2, string3] search the list with the given strings          (name, number, email)

* Exit (executable to handler as /exit)
  - exits the program gracefully
  - removes pipes
  - only receives input
  - logs the users to a file
