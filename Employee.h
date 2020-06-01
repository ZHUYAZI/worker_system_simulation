//
// Created by yazi on 31/05/2020.
//

#ifndef WORKER_MANGEMENT_EMPLOYEE_H
#define WORKER_MANGEMENT_EMPLOYEE_H
#pragma once

#include <iostream>
using namespace std;
#include "work.h"

class Employee : public worker{
public:
    Employee(int Id,string Name,int DeptId);
    virtual void showInfo();
    virtual string getDepName() ;
};







#endif //WORKER_MANGEMENT_EMPLOYEE_H
