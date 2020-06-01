//
// Created by yazi on 31/05/2020.
//

#ifndef WORKER_MANGEMENT_MANAGER_H
#define WORKER_MANGEMENT_MANAGER_H
#pragma once

#include <iostream>
#include "work.h"
using namespace std;

class Manager:public worker{
public:
    Manager(int Id,string Name,int DeptId);
    virtual void showInfo();
    virtual string getDepName();
};


#endif //WORKER_MANGEMENT_MANAGER_H
