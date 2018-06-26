#ifndef __COMMON__H__
#define __COMMON__H__

#include <iostream>
#include <string>
#include <map>
/*
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
*/

struct command_t
{
    std::string funcName;
    int data;
    int (*callbackFunc)(int data);
};

typedef command_t command_;

#endif
