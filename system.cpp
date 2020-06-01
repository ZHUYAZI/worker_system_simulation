//
// Created by yazi on 31/05/2020.
//
#include <iostream>
#include "workerManager.h"
#include "work.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"
using namespace std;

int main(){
    WorkerManager *wm = new WorkerManager();

    //test
//    worker *w1 =new Employee(1,"yazi",1);
//    w1->showInfo();
//    worker *M1 =new Manager(1,"yazi",1);
//    M1->showInfo();
//    worker *B1 =new Boss(1,"yazi",1);
//    B1->showInfo();


    int choice = 0;
    while (true){
        wm->Show_Menu();

        cout << "your choice: "<<endl;
        cin >> choice;
        switch (choice){
            case 0:
                wm->ExitSysteme();
                break;
            case 1:
                wm->Add_Emp();
                break;
            case 2:
                wm->Show_Emp();
                break;
            case 3:
                wm->Del_Emp();
                break;
            case 4:
                wm->Mod_Emp();
                break;
            case 5:
                wm->Find_emp();
                break;
            case 6:
                wm->Sort_Emp();
                break;
            case 7:
                wm->Clean_File();
                break;
            default:
                system("clear");
        }
    }

    delete wm;
    return 0;
}