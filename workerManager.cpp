//
// Created by yazi on 31/05/2020.
//

#include "workerManager.h"
WorkerManager::WorkerManager(){

    //not exit file
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    if (!ifs.is_open())
    {
        cout << "file don't exisit"<<endl;
        this->m_EmpNum=0;
        this->m_EmpArray=NULL;
        this->m_FileIsEmpty= true;
        ifs.close();
        return ;
    }
    //file exist not data
    char ch;
    ifs >> ch;
    if(ifs.eof()){
        cout << "empty data file"<<endl;
        this->m_EmpNum=0;
        this->m_EmpArray=NULL;
        this->m_FileIsEmpty= true;
        ifs.close();
        return ;
    }
    //file exist and data exist
    int num = this->get_EmpNum();
    cout << "total number of register worker is " << num << endl;
    this->m_EmpNum = num;

    this->m_EmpArray = new worker*[this->m_EmpNum];
    this->init_Emp();

}

WorkerManager::~WorkerManager(){
    if(this->m_EmpArray!=NULL){
        for (int i=0;i<this->m_EmpNum;i++){
            if(this->m_EmpArray[i]!=NULL){
                delete this->m_EmpArray[i];
                this->m_EmpArray[i]=NULL;
            }
        }
        delete [] this->m_EmpArray;
        this->m_EmpArray=NULL;
    }

}

void WorkerManager::Show_Menu() {
    cout<<"***********************************************"<<endl;
    cout<<"****************** WELCOME ********************"<<endl;
    cout<<"****************** 0. EXIT ********************"<<endl;
    cout<<"************  1. PLUS WORKERS  ****************"<<endl;
    cout<<"************* 2. SHOW WORKERS  ****************"<<endl;
    cout<<"************* 3. DELETE WORKERS ***************"<<endl;
    cout<<"************* 4. CHANGE WORKERS ***************"<<endl;
    cout<<"************* 5. SEARCH WORKERS ***************"<<endl;
    cout<<"************* 6. SORT WORKERS *****************"<<endl;
    cout<<"************* 7. EMPTY WORKERS ****************"<<endl;
    cout<<"***********************************************"<<endl;
    cout<<endl;
}

void WorkerManager::ExitSysteme() {
    cout << "welcome next time " << endl;
    system("read -p 'Press Enter to continue...' var");
    exit(0);
}

void WorkerManager::Add_Emp() {
    cout << "number of employee input" << endl;
    int addNum =0;
    cin >> addNum;

    if (addNum > 0){
//creat new space
        int newSize = addNum + this->m_EmpNum;

        worker **newSpace = new worker*[newSize];

        //copy old data

        if(this->m_EmpArray!=NULL){
            for(int i=0;i<this->m_EmpNum;i++){
                newSpace[i]=this->m_EmpArray[i];

            }
        }

        //add new data

        for(int i=0;i<addNum;i++){
            int id;
            string name;
            int dSelect;

            cout<<"please enter the number of the "<< i+1 <<" worker "<<endl;
            cin >>id;
            cout<<"please enter the name of the "<< i+1 <<" worker "<<endl;
            cin >> name;
            cout <<"please choose type"<<endl;
            cout <<"1.Worker"<<endl;
            cout <<"2.Manager"<<endl;
            cout <<"3.Boss"<<endl;
            cin >> dSelect;

            worker *worker = NULL;
            switch (dSelect){
                case 1:
                    worker =new Employee(id,name,1);
                    break;
                case 2:
                    worker =new Manager(id,name,2);
                    break;
                case 3:
                    worker =new Boss(id,name,3);
                    break;
            }

            newSpace[this->m_EmpNum+i]=worker;
        }

        delete [] this->m_EmpArray;
        this->m_EmpArray=newSpace;
        this->m_EmpNum = newSize;
        cout << "successful add "<< addNum<<" workers"<<endl;
        this->save();
        this->m_FileIsEmpty= false;

    } else{
        cout << "error input" << endl;
    }


    system("read -p 'Press Enter to continue...' var");
    system("clear");
}

void WorkerManager::save() {
    ofstream ofs;
    ofs.open(FILENAME,ios::out);//write to file
    for(int i=0;i<this->m_EmpNum;i++){
        ofs << this->m_EmpArray[i]->m_Id <<" "<<this->m_EmpArray[i]->m_Name << " "<< this->m_EmpArray[i]->m_DeptId << endl;
    }
    ofs.close();
}

int WorkerManager::get_EmpNum() {
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    int id;
    string name;
    int dId;
    int num=0;
    while(ifs>>id && ifs >>name && ifs >> dId)
    {
        num++;
    }

    return num;
}

void WorkerManager::init_Emp() {
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    int id;
    string name;
    int dId;
    int index = 0;
    while(ifs>>id && ifs >>name && ifs >> dId){
        worker *Worker = NULL;
        if(dId==0){
            Worker =new Employee(id,name,dId);
        }
        else if(dId==1){
            Worker =new Manager(id,name,dId);
        }
        else{
            Worker =new Boss(id,name,dId);
        }

        this->m_EmpArray[index] = Worker;
        index++;
    }
    ifs.close();
}

void WorkerManager::Show_Emp() {
    if(this->m_FileIsEmpty){
        cout << "file not exist or empty"<<endl;
    }
    else{
        for(int i=0;i<this->m_EmpNum;i++){
            this->m_EmpArray[i]->showInfo();
        }
    }
    system("read -p 'Press Enter to continue...' var");
    system("clear");
}

void WorkerManager::Del_Emp() {
    if (this->m_FileIsEmpty){
        cout << "file not exist or empty"<<endl;
    }
    else{
        cout << "Input id please "<<endl;
        int id =0;
        cin >> id;
        int index =this->isExist(id);

        if (index !=-1){
            for(int i = index;i<this->m_EmpNum-1;i++){
                this->m_EmpArray[i]=this->m_EmpArray[i+1];
            }
            this->m_EmpNum--;
            this->save();
            cout << "delete success"<<endl;
        }
        else{
            cout << "delete fail , can't find this id" <<endl;
        }
    }

    system("read -p 'Press Enter to continue...' var");
    system("clear");
}


int WorkerManager::isExist(int id) {
    int index =-1;
    for(int i =0;i<this->m_EmpNum;i++){
        if(id == this->m_EmpArray[i]->m_Id){
            index=i;
            break;
        }
    }
    return index;
}

void WorkerManager::Mod_Emp() {
    if (this->m_FileIsEmpty){
        cout << "file not exist or empty"<<endl;
    }
    else{
        cout<<"please enter the number of the  worker to modify "<<endl;
        int id;
        cin >>id;

        int ret =this->isExist(id);
        if (ret!=-1){
            delete this->m_EmpArray[ret];

            int newID =0;
            string name = " ";
            int dSelect = 0;

            cout << "Find this id "<< id <<" in the database, input the new id please "<<endl;
            cin >> newID;
            cout<<"please enter the new name "<<endl;
            cin >> name;
            cout <<"please choose new type"<<endl;
            cout <<"1.Worker"<<endl;
            cout <<"2.Manager"<<endl;
            cout <<"3.Boss"<<endl;
            cin >> dSelect;

            worker *worker = NULL;
            switch (dSelect){
                case 1:
                    worker =new Employee(id,name,1);
                    break;
                case 2:
                    worker =new Manager(id,name,2);
                    break;
                case 3:
                    worker =new Boss(id,name,3);
                    break;
                default:
                    break;
            }

            this->m_EmpArray[ret] = worker;
            cout << "successfully modify"<<endl;
            this->save();
        }
        else{
            cout << "modify fail , can't find this id" <<endl;
        }
    }
    system("read -p 'Press Enter to continue...' var");
    system("clear");
}

void WorkerManager::Find_emp() {
    if (this->m_FileIsEmpty){
        cout << "file not exist or empty"<<endl;
    }
    else{
        cout << "Input ways to search : "<< endl;
        cout << "1. By id "<< endl;
        cout << "2. By name "<< endl;
        int select =0;
        cin >> select;
        if(select==1){
            int id;
            cout << "input id"<<endl;
            cin >> id;

            int ret =isExist(id);
            if(ret!=-1){
                cout <<"Found it"<<endl;
                this->m_EmpArray[ret]->showInfo();
            }
            else{
                cout <<"Not Found"<<endl;
            }
        }
        else if (select==2){
            string name;
            cout << "Input name"<<endl;
            cin >> name;
            bool flag = false;
            for(int i=0;i<m_EmpNum;i++){
                if(this->m_EmpArray[i]->m_Name == name){
                    cout<<"find ok : "<<endl;
                    this->m_EmpArray[i]->showInfo();
                    flag = true;
                }
            }
            if(flag== false){
                cout <<"Not Found"<<endl;
            }

        }
        else{
            cout<<"Error choice"<<endl;
        }
    }
    system("read -p 'Press Enter to continue...' var");
    system("clear");
}

void WorkerManager::Sort_Emp() {
    if (this->m_FileIsEmpty){
        cout << "file not exist or empty"<<endl;
        system("read -p 'Press Enter to continue...' var");
        system("clear");
    }
    else{
        cout<<"Choose way to sort"<<endl;
        cout<<"1.Ascending order"<<endl;
        cout<<"2.Descending order"<<endl;
        int select =0;
        cin >> select;
        for (int i =0; i<this->m_EmpNum;i++){
            int MinOrMax=i;
            for (int j =i+1; j<this->m_EmpNum;j++){
                if (select==1){
                    if(this->m_EmpArray[MinOrMax]->m_Id>this->m_EmpArray[j]->m_Id){
                    MinOrMax=j;
                    }
                }else{
                    if(this->m_EmpArray[MinOrMax]->m_Id<this->m_EmpArray[j]->m_Id){
                        MinOrMax=j;
                    }
                }
            }

            if (i!=MinOrMax){
                worker * tmp = this->m_EmpArray[i];
                this->m_EmpArray[i] = this->m_EmpArray[MinOrMax];
                this->m_EmpArray[MinOrMax]=tmp;
            }
        }

        cout << "Sort ok"<<endl;
        this->save();
        this->Show_Emp();
    }

}

void WorkerManager::Clean_File() {
    cout << "Sure empty data ?"<<endl;
    cout << "1.yes"<<endl;
    cout<<"2.No"<<endl;
    int select = 0;
    cin >> select;
    if (select==1){
        ofstream ofs(FILENAME,ios::trunc);
        ofs.close();
        if(this->m_EmpArray!=NULL){
            for (int i=0;i<this->m_EmpNum;i++){
                delete this->m_EmpArray[i];
                this->m_EmpArray[i]=NULL;
            }
            delete [] this->m_EmpArray;
            this->m_EmpArray=NULL;
            this->m_EmpNum=0;
            this->m_FileIsEmpty= true;
        }

        cout << "Clear OK"<<endl;
    }
    system("read -p 'Press Enter to continue...' var");
    system("clear");
}
