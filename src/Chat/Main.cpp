#include "Message_list.h"
#include <chrono>

int main()
{
    Message_list sample;
    sample.add_to_list({"Sam", "hello rodina this is russia cyka blyat\n hahha make some sandwiches\n", 
    std::to_string(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()))});
    sample.add_to_list({"Frodo", "hello rodina this is russia cyka blyat\n hahha make some sandwiches\n", 
    std::to_string(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()))});
    sample.add_to_list({"Gandalf", "hello rodina this is russia cyka blyat\n hahha make some sandwiches\n", 
    std::to_string(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now()))});
    sample.print_list();
    return 0;
}