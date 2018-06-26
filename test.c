#include <stdlib.h>
#include <stdio.h>
#include <math.h>

char* itoa(int num,char* str,int radix)
{
    /*索引表*/
        char index[]="0123456789ABCDEF";
        unsigned unum;/*中间变量*/
        int i=0,j,k;
        /*确定unum的值*/
        if(radix==10&&num<0)/*十进制负数*/
        {
                unum=(unsigned)-num;
                str[i++]='-';
        }
        else unum=(unsigned)num;/*其他情况*/
        /*转换*/
        do{
                str[i++]=index[unum%(unsigned)radix];
                unum/=radix;
        }while(unum);
        str[i]='\0';
        /*逆序*/
        if(str[0]=='-')k=1;/*十进制负数*/
        else k=0;
        char temp;
        for(j=k;j<=(i-1)/2;j++)
        {
                temp=str[j];
                str[j]=str[i-1+k-j];
                str[i-1+k-j]=temp;
        }
        printf("%s\n", str);
        return str;
}

int loopmove(int i, int num)
{
    return (i<<num)|(i>>sizeof(int)*8-num);
}


int main(int argc, char *argv[])
{
    //int i = pow(2, 31)-1;
    int i = 0x7fffffff;
    printf("i = 0x%X\n", i);
    char ch[10];
    printf("i = %s\n", itoa(i, ch, 2));
    printf("i = %d, i<<3 = %d, i>>3 = %d, (i<<3)|(i>>3) = %d\n", i, i<<3, i>>3, (i<<3)|(i>>sizeof(int)*8-3));
    printf("loopmove(4, 1) = %d, %s, %s\n", loopmove(4, 1), itoa(4, ch, 2), itoa(loopmove(4, 1), ch, 2));
    printf("loopmove(4, -1) = %d, %s, %s\n", loopmove(4, -1), itoa(4, ch, 2), itoa(loopmove(4, -1), ch, 2));


/*
    int iarr[] = {1, 2, 3};
    printf("iarr[-1] = %d\n", iarr[-1]);
    int i = -1;
    for (i=-1; i<sizeof(iarr)/sizeof(int); i++)
    {
        printf("iarr[%d]=%d\n", i, iarr[i]);
    }
*/
    return 0;
}
