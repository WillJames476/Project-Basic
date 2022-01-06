#include <cstdlib>
#include <string>
#include <unistd.h>
#include "handler_ui.h"
#include "../Utilities/Transmitter.h"

int main()
{
    std::system("./account");
    handler_ui();
    return 0;
}