#include <unistd.h>
#include <signal.h>
#include <fcntl.h> 
#include<sys/types.h>
#include<sys/stat.h> 

#include <stdlib.h>
#include <stdio.h>

#include <list>

int init_daemon(int nochdir, int noclose)
{
    int fd;
    pid_t pid;

    //create first child process and exit parent process
    pid = fork();
    switch(pid) {
        case -1:    //failed to creat child process
            return -1;
        case 0:     //child process
            break;
        default:    //parent process exit
            exit(0);
    }
    //first child process continue
    
    //create session and set process group id
    if (-1 == setsid()) {
        return -2;
    }
    
    //create second child process and exit first child process
    pid = fork();
    switch(pid) {
        case -1:    //failed to creat child process
            return -1;
        case 0:     //second child process
            break;
        default:    //first child process exit
            exit(0);
    }
    //second child process continue, second child process is the daemon process
    
    //change work path
    if (nochdir == 0) {
        if (chdir("/") != 0) {
            perror("chdir error\n");
            return -3;
        }
    }

    //clear file mode creation mask
    umask(0);

    //close all opening fd
    if (noclose == 0 && (fd = open("/dev/null", O_RDWR, 0)) != -1) {  
        if(dup2(fd, STDIN_FILENO) < 0) {  
            perror("dup2 stdin");  
            return -4;  
        }  
        if(dup2(fd, STDOUT_FILENO) < 0) {  
            perror("dup2 stdout");  
            return -4;  
        }  
        if(dup2(fd, STDERR_FILENO) < 0) {  
            perror("dup2 stderr");  
            return -4;  
        }  
        if (fd > STDERR_FILENO) {  
            if(close(fd) < 0) {  
                perror("close");  
                return -5;  
            }  
        }  
    } 

    return 0;
}

void waitForChildProc(int signo)
{
    pid_t pid;
    int stat;
    while(pid = waitpid(-1, &stat, WNOHANG) > 0)
    {
        printf("child process %d exit.\n", pid);
    }
    printf("waitForChildProc exit.\n");
    return;
}

int daemon_loop()
{
    printf("this is daemon process[%d], parent process is [%d].\n", getpid(), getppid());
    signal(SIG_CHLD, waitForChildProc);
    return 0;
}

int child_loop()
{
    printf("this is child process[%d], parent process is [%d].\n", getpid(), getppid());
    return 0;
}

int createChildProcesses(int num, std::list<pid_t> &pidList)
{
    int i = 0;
    pid_t pid;
    for (i = 0; i<num; i++) {
        pid = fork();
        if (0 == pid || -1 == pid) {
            break;
        }  
    }
    
    if (pid == 0) {
        if (0 != child_loop())
        {
            exit(-1);
        }
        exit(0);
    } else if (pid == -1) {
        return -1;
    } else {
        pidList.push_back(pid);
    }

    return 0;
}

int main()
{
    if (0 != init_daemon(1, 1)) {
        return -1;
    }
    std:list<pid_t> pidList;
    if (0 != createChildProcesses(5, pidList)) {   
        //failed to create child proc, kill all exist child proc and exit
        for (std::list<pid_t>::iterator it = pidList.begin(); it != pidList.end(); ++it) {
            printf("kill child proc[%d]\n", *it);
            kill(*it, SIGABRT);
        }
        exit(-1);
    }
    if (0 != daemon_loop()) {
        exit(-1);
    }
    return 0;
}

