# Project Basic
* A basic set of applicatons.
* disclaimer this program's account system does
  minimal security measures, it is highly recomended
  to use burner accounts

# Prerequisites
* g++ 11.2 and up to compile the source code
* groff for documentation viewing
* make to build the project
* boost c++ library

# Third party libraries used
* This software includes third party open source software they are: 
1. Boost c++ library
   - boost::asio
   - boost::format

  * the Boost c++ library have their own license. Please see:
    Boost/LICENSE, https://github.com/boostorg/boost.git or www.boost.org

# Build instructions
1. clone the repository 
2. type make install on your terminal
3. type make on your terminal
4. enjoy
 
# Uninstalling
1. type make uninstall on the terminal

# Applications on this repo
* Client(executable as bin/client)
  - the client side application of the program

* Server(executable as bin/server)
  - the server side application of the program
  - it has the following applications:
	1. Account application
		- manages all the account opeartions:
		creation, deletion, and credential
		verifications.

	2. Communication line application:
		- manages all the permissions and accesses the user can have:
		can grant, and can add a user to access.

	3. Todolist application]
		- manages all the task given to the user by 
		himself or other permitted users.
