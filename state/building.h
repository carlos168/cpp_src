#ifndef BUILDING_H
#define BUILDING_H
#include "state.h"

#include <map>
#include <iostream>
using namespace std;

enum StateType
{
    BUILDING, INJURED, REPAIR, UPGRADE, PRODUCTION
};

class absBuilding
{
public:
    absBuilding(char* name):mName(name){};
    virtual void show() 
    {
        cout<<mName<<"表现:"<<endl;
        map<StateType, absState*>::iterator beg = mStates.begin();
        for ( ; beg != mStates.end(); beg++)
        {
            beg->second->show();
        }
        cout<<endl;
    };
    //实现删除一个特效
    void eraseState(StateType type)
    {
        auto result = mStates.find(type);
        if(result != mStates.end())
            mStates.erase(result);
    };
protected:
    char* mName;
    map<StateType, absState*> mStates;
};



class concreteBuilding:public absBuilding
{
public:
    concreteBuilding(char* name):absBuilding(name)
    {
        mStates[BUILDING] = new buildingState();
    }

    void upGrade()
    {
        auto result = mStates.find(UPGRADE);
        if(result == mStates.end())
        {
            mStates[UPGRADE] = new upGradeState();
        }
        //升级的时候必须是建造过程已经结束，所以需要删掉“建筑”状态
        eraseState(BUILDING);
        //升级的时候不能进行生产
        eraseState(PRODUCTION);
    }

    void production()
    {
        auto result = mStates.find(PRODUCTION);
        if(result == mStates.end())
        {
            mStates[PRODUCTION] = new upGradeState();
        }
        //生产的时候必须已经建造完成
        eraseState(BUILDING);
        //生产的时候不能升级
        eraseState(UPGRADE);
    }

    void injured()
    {
        auto result = mStates.find(INJURED);
        if(result == mStates.end())
        {
            mStates[INJURED] = new fireState();
        }
    }

    void repair()
    {
        auto injuredVal = mStates.find(INJURED);
        if(injuredVal == mStates.end())
            return;
        auto result = mStates.find(REPAIR);
        if(result == mStates.end())
        {
            mStates[REPAIR] = new repairState();
        }
    }
};

#endif

