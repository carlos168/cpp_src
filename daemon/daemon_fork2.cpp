#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>// open
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<sys/wait.h>
#include<signal.h>

#define MAXFILE 65535

volatile sig_atomic_t _running = 1;
int fd;

// signal handler
void sigterm_handler(int arg)
{   
    _running = 0;
}

int main(int argc, const char *argv[])
{
    pid_t pid;
    char *buf = "This is a Daemon, wcdj\n";
    /* 屏蔽一些有关控制终端操作的信号
     * 防止在守护进程没有正常运转起来时，因控制终端受到干扰退出或挂起
     * */
    signal(SIGINT,  SIG_IGN);// 终端中断
    signal(SIGHUP,  SIG_IGN);// 连接挂断
    signal(SIGQUIT, SIG_IGN);// 终端退出
    signal(SIGPIPE, SIG_IGN);// 向无读进程的管道写数据
    signal(SIGTTOU, SIG_IGN);// 后台程序尝试写操作
    signal(SIGTTIN, SIG_IGN);// 后台程序尝试读操作
    signal(SIGTERM, SIG_IGN);// 终止

    //首先第一次fork：这里第一次fork的作用就是让shell认为这条命令已经终止，不用挂在终端输入上;再一个是为了后面的setsid服务，因为调用setsid函数的进程不能是进程组组长(会报错Operation not permitted)，如果不fork子进程，那么此时的父进程是进程组组长，无法调用setsid。所以到这里子进程便成为了一个新会话组的组长。
    
    //[1] fork child process and exit father process
    pid = fork();
    if(pid < 0)
    {
        perror("fail to fork");
        exit(0);
    }
    else if(pid > 0)
    {
        exit(0);
    }
    else
    {
        //[2]create a new session
        setsid();

        //[3] umask 0
        umask(0);
    
        //第二次fork：第二次fork是为了避免后期进程误操作而再次打开终端。因为打开一个控制终端的前提条件是该进程必须为会话组组长，而我们通过第二次fork，确保了第二次fork出来的子进程不会是会话组组长。
        pid = fork();
        if(pid != 0)
        {
            exit(0);
        }

        //[4] set current path
        chdir("/");
        /*char szPath[1024];
        if(getcwd(szPath, sizeof(szPath)) == NULL)
        {
            perror("getcwd");
            exit(1);
        }
        else
        {
            chdir(szPath);
            printf("set current path succ [%s]\n", szPath);
        }*/

        //[5] close useless fd
        int maxfd = getdtablesize();
        while(maxfd--)
        {
            close(maxfd);
        }

        // [6] set termianl signal
        signal(SIGTERM, sigterm_handler);

        // do sth in loop
        while(_running)
        {   
            if (write(fd, buf, strlen(buf)) != strlen(buf))
            {   
                perror("write");
                close(fd);
                exit(1);
            }   

            usleep(1000*1000);// 1 s
        }   
        close(fd);

        // print data
        if((fd = open("outfile", O_RDONLY)) < 0)
        {   
            perror("open");
            exit(1);
        }
        char szBuf[1024] = {0};
        if(read(fd, szBuf, sizeof(szBuf)) == -1)
        {
            perror("read");
            exit(1);
        }
        printf("read 1024 bytes:\n%s\n", szBuf);

        close(fd);
    }
    return 0;
}
