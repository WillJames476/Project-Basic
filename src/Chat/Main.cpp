#include "Message_tuple.h"
#include <chrono>

int main()
{
    Message_tuple sample{{"Sam", "hi, sam from India, 12, 4"}};
    sample.print_message();
    return 0;
}