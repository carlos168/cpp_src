#include <stdlib.h>
#include <stdio.h>

#include "args_parser.hpp"

int main(int argc, char *argv[])
{
    Args_parser parser;
    parser.parse_args(argc, argv);
    parser.show();
    printf("process name is: %s\n", parser.get_process_name().c_str());
    std::string value = "";
    parser.get_opt("test", &value);
    printf("key=%s, value=%s\n", "test", value.c_str());
    return 0;
}
