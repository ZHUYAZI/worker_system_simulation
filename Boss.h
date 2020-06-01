//
// Created by yazi on 31/05/2020.
//

#ifndef WORKER_MANGEMENT_BOSS_H
#define WORKER_MANGEMENT_BOSS_H
#pragma once

#include <iostream>
#include "work.h"
using namespace std;

class Boss:public worker{
public:
    Boss(int Id,string Name,int DeptId);
    virtual void showInfo();
    virtual string getDepName();
};



#endif //WORKER_MANGEMENT_BOSS_H
