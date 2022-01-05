#include <cstdlib>
#include <cstdio>
#include <sys/types.h>
#include <sys/stat.h>
#include "handler_ui.h"

int main()
{
    mkfifo("tmp/cows", 0777);
    std::system("./account");
    handler_ui();
    return 0;
}