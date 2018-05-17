#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/*
平滑加权轮询算法实现
*/

typedef struct
{
    int weight;
    int cur_weight;
    char name[3];
}server;

int getsum(int *set, int size)
{
    int i = 0; 
    int res = 0;

    for (i = 0; i < size; i++)
        res += set[i];

    return res;
}

server *initServers(char **names, int *weights, int size)
{
    int i = 0;
    server *ss = calloc(size+1, sizeof(server));

    for (i = 0; i < size; i++)
    {
        ss[i].weight = weights[i];
        memcpy(ss[i].name, names[i], 3);
        ss[i].cur_weight = 0;
    }
    return ss;
}

int getNextServerIndex(server *ss, int size)
{
    int i ;
    int index = -1;
    int total = 0;

    printf("size =%d\n", size);
    for (i = 0; i < size; i++)
    {
        printf("i = %d==============\n", i);
        ss[i].cur_weight += ss[i].weight;
        total += ss[i].weight;

        printf("ss[%d].cur_weight=%d, ss[%d].cur_weight=%d\n", index, ss[index].cur_weight, i, ss[i].cur_weight);
        if (index == -1 || ss[index].cur_weight < ss[i].cur_weight)
        {
            printf("index = %d, i = %d =======\n", index, i);
            index = i;
        }
    }

    ss[index].cur_weight -= total;
    return index;
}

void wrr_nginx(server *ss, int *weights, int size)
{
    int i = 0;
    int index = -1;
    int sum = getsum(weights, size);
    printf("sum=%d\n", sum);

    for (i = 0; i < sum; i++) 
    {
        index = getNextServerIndex(ss, size);
        printf("%s(%d) ", ss[index].name, ss[index].weight);
    }
    printf("\n");
}

int main()
{
    int i = 0;
    int weights[] = {4, 2, 1};
    char *names[] = {"a", "b", "c"};
    int size = sizeof(weights) / sizeof(int);

    server *ss = initServers(names, weights, size);

    printf("server is ");
    for (i = 0; i < size; i++)
    {
        printf("%s(%d) ", ss[i].name, ss[i].weight);
    }
    printf("\n");

    printf("\nwrr_nginx sequence is ");
    wrr_nginx(ss, weights, size);

    return 0;
}
