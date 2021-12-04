#include "Message_tuple.h"
#include <chrono>

int main()
{
    Message_tuple sample{"Sam", "hello rodina this is russia cyka blyat\n hahha make some sandwiches\n", 
    std::to_string(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()))};
    sample.print_message();
    return 0;
}