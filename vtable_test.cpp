#include <stdlib.h>
#include <stdio.h>

#pragma pack(1)

class base {
public:
    int mBase;
    virtual int func(){return 0;}
    char ch;
};

class A: public base {
public:
    int mA;
};
#pragma pack(2)
class B: public base {
public:
    int mB;
};


class C: public A, public B {
public:
    int mC;
};


int main()
{
    printf("sizeof(base)=%lu, sizeof(A)=%lu, sizeof(B)=%lu, sezeof(C)=%lu\n", 
            sizeof(base), sizeof(A), sizeof(B), sizeof(C));
    return 0;
}
