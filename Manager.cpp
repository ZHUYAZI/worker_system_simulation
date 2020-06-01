//
// Created by yazi on 31/05/2020.
//

#include "Manager.h"
Manager::Manager(int Id,string Name,int DeptId){
    this->m_Id = Id;
    this->m_Name = Name;
    this->m_DeptId = DeptId;
}

void Manager::showInfo() {
    cout << " worker ID : "<< this->m_Id
         <<" , worker name : "<< this->m_Name
         << " , post : "<< this->getDepName()
         << " , duty : finish boss work, distribute work to worker "<<endl;
}

string Manager::getDepName() {
    return string("manager");
}