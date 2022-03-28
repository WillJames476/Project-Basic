# Project Basic
* A basic set of applicatons.
* disclaimer this program's account system does
  minimal security measures, it is highly recomended
  to use burner accounts

# Prerequisites
* g++ 11.2 and up to compile the source code
* meson to build and compile the binaries
* boost c++ library

# Third party libraries used
* This software includes third party open source software they are: 
1. Boost c++ library
   - boost::asio
   - boost::format
   - boost::gregorian

  * the Boost c++ library have their own license. Please see:
    Boost/LICENSE, https://github.com/boostorg/boost.git or www.boost.org

# Build instructions
1. clone the repository 
2. create data folder on the project's root directory
3. type make build
4. type make compile -C build
4. enjoy
 
# Uninstalling
1. delete the project folder

# Applications on this repo

* Client(executable as build/srcClient/client)

  - expects an ip address and a port as the program
  arguments
  
  - the client side application of the program
 
  - communicates with the server
    Operations are the following:
    GET, DELETE, POST, PUT.

* Server(executable as build/src/Server/server)

  - expects an ip address and a port as the program
  arguments.

  - must be run under administrator/ super user
  priviledges

  - the server side application of the program
  
  - it has the following applications:
  
	1. Account application
		- manages all the account opeartions:
		creation, deletion, and credential
		verifications.

	2. Communication line application:
		- manages all the permissions and accesses the user can have:
		can grant, revoke, delete, and can add a user to access.

	3. Todolist application:
		- manages all the task given to the user by 
		himself or other permitted users.


