#ifndef STATE_H
#define STATE_H
#include <iostream>
using namespace std;

class absState{
public:
    virtual void show() = 0;
};

class buildingState:public absState{
public:
    virtual void show()
    {
        cout<<"建造特效  ";
    }
};

class fireState:public absState{
public:
    virtual void show()
    {
        cout<<"受伤着火  ";
    }
};

class productionState:public absState{
public:
    virtual void show()
    {
        cout<<"生产白光  ";
    }
};

class upGradeState:public absState
{
public:
    virtual void show()
    {
        cout<<"升级蓝光  ";
    }
};

class repairState:public absState
{
public:
    virtual void show()
    {
        cout<<"修复绿光  ";
    }
};

#endif

