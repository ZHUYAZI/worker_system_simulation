//
// Created by yazi on 31/05/2020.
//

#include "Employee.h"

Employee::Employee(int Id, string Name, int DeptId) {
    this->m_Id = Id;
    this->m_Name = Name;
    this->m_DeptId = DeptId;
}


void Employee::showInfo() {
    cout << " worker ID : "<< this->m_Id
    <<" , worker name : "<< this->m_Name
    << " , post : "<< this->getDepName()
    << " , duty : finish daily work "<<endl;

}

string Employee::getDepName() {
    return string("normal worker");

}

