#include<iostream>
#include<fstream>
#include<map>
#include<vector>
#include<string>
using namespace std;
int task;

map<int , bool> m;
vector<string> data;   //vector will store every data so that we can edit it


struct todo {
    public:
    int task_no[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    string task_des;
    bool isDone;
};


void question ()
{
    
    cout<<endl<<endl;
    cout<<"\t\t 1. Add new Task "<<endl;
    cout<<"\t\t 2. Mark Task as done "<<endl;
    cout<<"\t\t 3. Show Tasks "<<endl;
    cout<<"\t\t 5. Quit "<<endl<<endl;
    cout<<"\t\t Enter your choice :";
    cin>>task;
}
void bannerLine()
{
    cout<<"______________________________________________________________________";
    cout<<"\n\t\t\t\t My Todo list "<<endl;
    cout<<"______________________________________________________________________";
    return;
}


void AddTask()
{
    int i=0;
    todo td;
    system("cls");
    bannerLine();


    
    cout<<"\n\nEnter your task  :\n";
    cin.get();
    getline(cin , td.task_des);
    data.push_back(td.task_des);
    int m_done = td.task_no[i++];
    m[m_done] = false;
    system("cls");
    bannerLine();
    cout<<"\n\n___________________________";
    cout<<"| Added successfully | ";
    cout<<"____________________________\n";
    char addChoice;
    cout<<"\n\nAdd more task ? (y/n) : ";
    cin>>addChoice;
    if(addChoice == 'y')
    {
       AddTask();
    }
    else {
        system("cls");
    }
    
    ofstream fout;
    fout.open("Proj_final_text.txt" , ios :: app);
    //fout<<endl<<td.task_no;
    fout<<td.task_no[i++];
    fout<<" : "<<td.task_des;
    fout<<endl;
    fout.close();
    
    bannerLine();
    question();
}

void ShowTask() {
    int j=0;
    system("cls");
    todo td;
    bannerLine();

    cout<<"\nThe Tasks you have to complete are :\n";
    ifstream hin;
    hin.open("Proj_final_text.txt");
    while(!hin.eof())
    {
     
        hin.ignore();
        getline(hin , td.task_des);
        if(td.task_des !="")
        {
            int m_print = td.task_no[j];
            if(m[m_print] == false){
            cout<<td.task_no[j++]<<"  [X] ";
            cout<<td.task_des;
            cout<<endl;
            }
            else {
            cout<<td.task_no[j++]<<"  [/] ";
            cout<<td.task_des;
            cout<<endl;

            }
        }
    }
    hin.close();
    char is_exit;
    cout<<"press y to  come home screen -";
    cin>>is_exit;
    if(is_exit == 'y')
    {
        system("cls");
        bannerLine();
        question();
    }
    else {
        ShowTask();
    }
    return;

}
void MarkDone() {
    system("cls");
    todo td;
    int mark;
    cout<<endl<<"Enter task to mark done :";
    cin>>mark;
    m[mark] = true;
    cout<<"\nTask is mark as done //";
    system("cls");
    cout<<"\nupdated tasks are :\n";
    
    ShowTask();

    
}

void Quit()
{
    system("cls");
    cout<<"Thank you & GoodBye !!"<<endl;
    return;
}

int main()
{
    system("cls");
    bannerLine();

    question();
    do {
    switch(task) {
        case 1:
        AddTask();
        break;
        case 2:
        MarkDone();
        break;
        case 3:
        ShowTask();
        break;
        case 4:
        Quit();
        exit(0);
    }
    }while(1);
    return 0;

}
