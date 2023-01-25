// project of  Hospital management system.
#include<iostream>
#include<fstream>
#include<cstring>
#include<cstdio>
#include<process.h>
#include<windows.h>
#include<unistd.h>
#include<conio.h>
using namespace std;
void welcomescreen();
void title();
void mainmenu ();
void loginscreen();
class hospital_management
{
    private:
    // Variables for patient Deatails
    char patient_name[100];
    char id[10];
    char problem[50];
    char prescribed_doctor[50];
    char email[20];
    char mobile[20];
    public:
    void  mainmenu();
    void welcomescreen();
    void title();
    void insert();
    void loginscreen();
    void display();
    void modify();
    void search();
    void deleted();
};

int main()
{
    system("cls");
    hospital_management system;
system.welcomescreen();
getch();
return 0;

}
void hospital_management::welcomescreen()
{
cout<<"\t\t\t\t==========================================================="<<endl;
cout<<"\t\t\t\t==========================================================="<<endl;
cout<<"\t\t\t\t==========================================================="<<endl;
cout<<"\t\t\t\t\t\tWELCOME TO AMRITSAR AIIMS"<<endl;
cout<<"\t\t\t\t==========================================================="<<endl;
cout<<"\t\t\t\t==========================================================="<<endl;
cout<<endl<<endl<<endl;
cout<<"press any key to continue............."<<endl;
loginscreen();
getch();

}
void hospital_management::title(){
cout<<"\t\t\t\t==========================================================="<<endl;
cout<<"\t\t\t\t==========================================================="<<endl;
cout<<"\t\t\t\t\t\t\tAMRITSAR AIIMS "<<endl;
cout<<"\t\t\t\t==========================================================="<<endl;
cout<<"\t\t\t\t==========================================================="<<endl;
}
void hospital_management::mainmenu(){
system("cls");
int choice;
char x;
title();
    cout<<endl<<endl<<endl;
    cout<<"\n\t\t\t\t\t 1. Enter New Record "<<endl;
    cout<<"\n\t\t\t\t\t 2. Display Record "<<endl;
    cout<<"\n\t\t\t\t\t 3. Modify Record"<<endl;
    cout<<"\n\t\t\t\t\t 4. Search Record"<<endl;
    cout<<"\n\t\t\t\t\t 5. Delete Record"<<endl;
    cout<<"\n\t\t\t\t\t 6. Exit"<<endl;

cout<<endl<<endl<<endl<<endl;
cout<<"choose from 1 to 6:-"<<endl;
cin>>choice;
switch(choice)
    {
        case 1:
        do{
            insert();
            cout<<"\n\n\t\t\t Add Another Employee Record Press (Y,N):";
            cin>>x; 
        }while(x=='Y' || x=='y');
        if(x!='Y'|| x!='y'){
            mainmenu();
        }
        break;
        case 2:
        display();
        break;
        case 3:
         do{
            modify();
            cout<<"\n\n\t\t\t Add Another Employee Record Press (Y,N):";
            cin>>x; 
        }while(x=='Y' || x=='y');
        if(x!='Y'|| x!='y'){
            mainmenu();
        }
       
        break;
        case 4:
        search();
        break;
        case 5:
        deleted();
        break;
        case 6:
        system("cls");
        cout<<"\n\n\t\t\t>> HOSPITAL MANAGEMENT SYSTEM- BY GAUATAM KUMAR\n\t\t\tKunal Verma\n\t\t\tMayank priya\n\t\t\tFahiyan Sikandar\n";
        sleep(9);
        exit(0);
        break;
        default:
        cout<<"\n\n\n\t\t Invalid Choice ...please Try Again..\n";
        break;
    }
    getch();

}
void hospital_management::insert()
{
    system("cls");
    title();
    fstream file;
    cout<<"\t\t\t\n==========================================================================="<<endl;
    cout<<"\t\t\t\t--------------patient Insert Data----------------------"<<endl;
    cout<<"\t\t\t\n=========================================================================";
    cout<<"\n Enter patient Name :";
    cin >> patient_name;
    cout<<"\n Enter patient ID [max 4 digits]:";
    cin>>id;
    cout<<"\n Enter patient problem:";
    cin>>problem;
    cout<<"\n Enter prescribed doctor :";
    cin>>prescribed_doctor;
    cout<<"\n Enter patient Email id :";
    cin>>email;
    cout<<"\n Enter patient mobile number :";
    cin>>mobile ;
  
  
    file.open("patient_record.txt",ios::app | ios::out);
    file<<"   "<< patient_name<<"   "<<id<<"   "<<problem<<"   "<<prescribed_doctor<<"   "<<email<<"   "<<mobile<<"   ";
    file.close();
}

void hospital_management::loginscreen(){
system("cls");
title();
int e=0;
char username[20];
char password[20];
char orginal_name[20]="gautam";
char orginal_password[20]="12345";
do{
cout<<"\t Enter your username and password to login "<<endl;
cout<<endl<<endl<<endl<<endl;
cout<<"\t\n Enter your username::    ";
cin>>username;
cout<<"\t \nEnter your password::    ";
cin>>password;
if(strcmp(username,orginal_name)==0 && strcmp(password,orginal_password)==0)
{
    cout<<"\n\n\n\n\t\t\t\t|Verifying Patient |\n\t\t\t\t";
                for(int a=1;a<9;a++)
                {
                    Sleep(500);
                    cout<<"...";
                }
                cout<<"\n\nAccess Granted...\n\n";
                system("pause");
        cout<<endl<<endl<<"\t\t\t.........Login successful..."<<endl;
       // system("cls");
        getch();
        mainmenu();
        break;
}
else
{
cout<<endl<<"\t password is incorrect (Try Again):::"<<endl;
e++;
getch() ;
}
}while(e<=1);
if (e>1)
{
cout<<"you have cross the limit .you cannot Login:::::......"<<endl;
getch();
exit(-1);
}
}
void hospital_management::display()
{
    title();
    system("cls");
    title();
    int total =1;
    fstream file;
    cout<<"\n\n\t\t\t==============================================="<<endl;
    cout<<"\n\n\t\t\t\tPatient Record Data"<<endl;
    cout<<"\n\n\t\t\t==============================================="<<endl;
     file.open("patient_record.txt",ios::in);
     if(!file)
     {
         cout<<"File not Found....Error opening"<<endl;
         file.close();
     }
     else
     {
         file>>patient_name>>id>>problem>>prescribed_doctor>>email>>mobile;
         cout<<"\n\n==================================================================================================================="<<endl;
         cout<<"\n ||   NAME  ||   ID   || PROBLEM  ||PRESCRIBED DOCTOR||        EMAIL         ||  MOBILENOS"<<endl;
         cout<<endl;
         cout<<"======================================================================================================================="<<endl;
         while(!file.eof())
         {
             cout<<endl;
             cout<<total++ <<". "<< patient_name<<"\t"<<id<<"\t"<<problem<<"\t"<<prescribed_doctor<<"\t"<<email<<"\t"<<mobile;
             file>>patient_name>>id>>problem>>prescribed_doctor>>email>>mobile;
         }
     }
     file.close();
     getch();
     mainmenu();
}
void hospital_management:: modify()
{
    system("cls");
    title();
    char checkid[5];
    int found=0;
    fstream file,file1;
    cout<<"\n\n\n========================================================================";
    cout<<"\t\t\t\tPatient Modify Data";
    cout<<"\n\n=========================================================================";
    cout<<endl<<endl;
    file.open("patient_record.txt",ios::in);
    if(!file)
     {
         cout<<"File not Found....Error opening"<<endl;
         file.close();
     }
     else
     {
         cout<<"Enter Patient  ID: "<<endl;
         cin>>checkid;
         file1.open("record.txt",ios::app|ios::out|ios::ate);
         file >>patient_name >>id >> problem >> prescribed_doctor >> email>> mobile;
         while(!file.eof())
         {
             if(strcmp(checkid,id)==0)
             {
                cout<<"\n Enter patient Name :";
                cin >> patient_name;
                cout<<"\n Enter patient ID [max 4 digits]:";
                cin>>id;
                cout<<"\n Enter patient problem:";
                cin>>problem;
                cout<<"\n Enter prescribed doctor :";
                cin>>prescribed_doctor;
                cout<<"\n Enter patient Email id :";
                cin>>email;
                cout<<"\n Enter patient mobile number :";
                cin>>mobile ;
                cout<<"\n\nSuccessfully Modify Details of Patient";
                file1<<"   "<< patient_name<<"   "<<id<<"   "<<problem<<"   "<<prescribed_doctor<<"   "<<email<<"   "<<mobile<<" \n  ";
                found++;
             }
             else
             {
                 file1<<"   "<< patient_name<<"   "<<id<<"   "<<problem<<"   "<<prescribed_doctor<<"   "<<email<<"   "<<mobile<<" \n  ";

             }
             file >>patient_name >>id >> problem >> prescribed_doctor >> email>> mobile;
         }
         if (found==0)
         {
             cout<<"\n\n\t\tPatient ID not found...Please Try Again";
         }
         file1.close();
         file.close();
         remove("patient_record.txt");
         rename("record.txt","patient_record.txt");
     }
     mainmenu();
}
void hospital_management::search()
{
    //Display all details according to patient's ID
    system("cls");
    title();
    fstream file;
    char checkid[5];
    cout<<"\n\t\t\t============================================================================"<<endl;
    cout<<"\t\t\t\tPATIENT RECORD DATA"<<endl;
    file.open("patient_record.txt",ios::in);
    cout<<"\n\nEnter patient ID::"<<endl;
    cin>>checkid;
    if(!file)
     {
         cout<<"File not Found....Error opening"<<endl;
         file.close();
     }
     else
    {
        file >>patient_name >>id >> problem >> prescribed_doctor >> email>> mobile;
        while(!file.eof())
        {
            if(strcmp(checkid,id)==0)
        {
            cout<<"\n============================================"<<endl;
            cout<<"patient Name :"<<patient_name<<"\n";
            cout<<"patient ID :"<<id<<"\n";
            cout<<"patient problem:"<<problem<<"\n";
            cout<<"Prescribed doctor:"<<prescribed_doctor<<"\n";
            cout<<"patient email:"<<email<<"\n";
            cout<<"patient Mobile :"<<mobile<<"\n";
            cout<<"\n============================================"<<endl;
        }
        file >>patient_name >>id >> problem >> prescribed_doctor >> email>> mobile;
        getch();
        }
    }
    file.close();
    getch();
    mainmenu();
}
void hospital_management::deleted()
{
    system("cls");
    char checkid[5];
    fstream file,file1;
    int found=0;
    cout<<"\n\n\t\t\t============================================================"<<endl;
    cout<<"\t\t\t\t\t\t\tPATIENT  DELETE DATA"<<endl;
    cout<<"\n\n\t\t\t============================================================"<<endl;
    file.open("patient_record.txt",ios::in);
    if(!file)
     {
         cout<<"File not Found....Error opening"<<endl;
         file.close();
     }
     else
    {
    cout<<"\nEnter Patient ID to Remove Data :";
    cin>>checkid;
    file1.open("record.txt",ios::app|ios::out);
    file >>patient_name >>id >> problem >> prescribed_doctor >> email>> mobile;
    while(!file.eof())
    {
        if(strcmp(checkid,id)!=0)
        {
            file1 <<"   "<< patient_name<<"   "<<id<<"   "<<problem<<"   "<<prescribed_doctor<<"   "<<email<<"   "<< mobile<<" \n  ";
        }
        else
        {
            found++;
            cout<<"\n\t\t\tSuccesfully Delete Data.....";
            getch();
        }
        file >>patient_name >>id >> problem >> prescribed_doctor >> email>> mobile;
    }
    if(found==0)
    {
        cout<<"\n\n\tPatient ID Not Found..Please Try Again...";
    }
    file1.close();
    file.close();
    remove("patient_record.txt");
    rename("record.txt","patient_record.txt");
    //getch();
    mainmenu();
}
}