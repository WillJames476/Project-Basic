#include <iostream>
#include <cstdlib>
#include <cstdint>

#include <boost/asio.hpp>
#include <server_utilities.h>
#include <client_runtime.hpp>

int
main(int32_t argc,
     char** argv)
{
  std::ios_base::sync_with_stdio(false);

  if(argc == 3)
    {
      execute_client(argv);
    }
  else
    {
      std::cerr << "invalid argument count\n";
      return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
