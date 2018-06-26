#include <stdio.h>  
#include <stdlib.h>  
#include <unistd.h>  
#include <fcntl.h>  
#include <limits.h>  
  
int main(int argc, char *argv[])  
{  
    char strCurPath[PATH_MAX];  
    printf("1 pid = %d\n", getpid());
    printf("1 ppid = %d\n", getppid());
    printf("1 sid = %d\n", getsid(getpid()));

    if(daemon(1, 1) < 0)  
    {
      
        printf("2 pid = %d\n", getpid());
        printf("2 ppid = %d\n", getppid());
        printf("2 sid = %d\n", getsid(getpid()));
        perror("error daemon...\n");  
        exit(1);  
    }  
    sleep(1);  

    printf("3 pid = %d\n", getpid());
    printf("3 ppid = %d\n", getppid());
    printf("3 sid = %d\n", getsid(getpid()));
    
    if(getcwd(strCurPath, PATH_MAX) == NULL)  
    {  
        perror("error getcwd\n");  
        exit(1);  
    }

    printf("current path: %s\n", strCurPath);  
    return 0;  
}  


