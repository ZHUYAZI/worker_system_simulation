//
// Created by yazi on 31/05/2020.
//

#include "Boss.h"
Boss::Boss(int Id,string Name,int DeptId){
    this->m_Id = Id;
    this->m_Name = Name;
    this->m_DeptId = DeptId;
}

void Boss::showInfo() {
    cout << " worker ID : "<< this->m_Id
         <<" , worker name : "<< this->m_Name
         << " , post : "<< this->getDepName()
         << " , duty :  distribute work to manager "<<endl;
}

string Boss::getDepName() {
    return string("Boss");
}