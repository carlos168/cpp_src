#include <stdlib.h>
#include <stdio.h>

enum err_code
{
    err_success = 0,
    err_system = 1
};

int main(int argc, char *argv[])
{
    printf("main is running ...\n");
    printf("err_success=%d\n", err_success);
	return 0;
}
