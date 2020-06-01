//
// Created by yazi on 31/05/2020.
//

#ifndef WORKER_MANGEMENT_WORK_H
#define WORKER_MANGEMENT_WORK_H
#pragma once

#include <iostream>
#include "string"
using namespace std;

class worker{
public:
    virtual void showInfo() = 0;
    virtual string getDepName() = 0;
    int m_Id;
    string m_Name;
    int m_DeptId;

};



#endif //WORKER_MANGEMENT_WORK_H
