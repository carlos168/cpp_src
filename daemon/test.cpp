#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    printf("maxfd = %d\n", getdtablesize());
    return 0;
}
