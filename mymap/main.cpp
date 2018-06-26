/*
#include <iostream>
#include <string>
#include <map>
*/

#include "common.h"

//struct command_t
//{
//   std::string funcName;
//   int data;
//   int (*callbackFunc)(int data);
//};
//typedef command_t command_;

int add(int data)
{   
    std::cout<<"add is called."<<"\n";
    return data+1;
}

int addData(int data)
{   
    std::cout<<"addData is called."<<"\n";
    return data+5;
}

static const command_ commands[] = {
    {"add", 10, &add},
    {"addData", 20, &addData}
};

int main(int argc, char *argv[])
{
	std::map<std::string, command_> mymap;
    for(unsigned int i=0; i<sizeof(commands)/sizeof(command_); i++)
    {
        mymap.insert(std::pair<std::string, command_>(commands[i].funcName, commands[i]));
    }

    std::map<std::string, command_>::iterator it;
    for(it=mymap.begin(); it!=mymap.end(); it++)
    {
        std::cout<<it->first<<" => "<<(it->second).data<<"\n";
        std::cout<<it->second.callbackFunc(it->second.data)<<"\n";
    }
    
    
    return 0;
}
