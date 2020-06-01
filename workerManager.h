//
// Created by yazi on 31/05/2020.
//
#define FILENAME "/home/yazi/CLionProjects/worker_mangement/data_saved/empFile.txt"

#ifndef WORKER_MANGEMENT_WORKERMANAGER_H
#define WORKER_MANGEMENT_WORKERMANAGER_H
#pragma once

#include <iostream>
#include <fstream>
#include "work.h"
#include "Employee.h"
#include "Boss.h"
#include "Manager.h"
using namespace std;


class WorkerManager
{
public:
    WorkerManager();
    ~WorkerManager();
    void Show_Menu();
    void ExitSysteme();
    int m_EmpNum;
    worker **m_EmpArray;
    void Add_Emp();
    void save();
    //justify the data file if is empty
    bool m_FileIsEmpty;
    int get_EmpNum();
    void init_Emp();
    void Show_Emp();
    void Del_Emp();
    int isExist(int id);
    void Mod_Emp();
    void Find_emp();
    void Sort_Emp();
    void Clean_File();
};



#endif //WORKER_MANGEMENT_WORKERMANAGER_H
