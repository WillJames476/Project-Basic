#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <server_runtime.hpp>

int
main(int32_t argc,
     char** argv)
{
  std::ios_base::sync_with_stdio(false);

  if(argc == 3)
    {
      execute_server(argv);
    }
  else
    {
      std::cerr << "argument count is not 3\n";
      return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
