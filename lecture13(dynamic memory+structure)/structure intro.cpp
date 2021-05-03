#include<iostream>
using namespace std;
struct student
{
    char name[100];
    int age;
    char gender;
};
int main()
{
    /*
    student s;//similar to int s
    //input;
    cout<<"enter name"<<endl;
    cin.getline(s.name,100);//(.)operator is used to access in object s
    cout<<"enter age"<<endl;
    cin>>s.age;
    cout<<"enter gender"<<endl;
    cin>>s.gender;
    //output
    cout<<"details of student are"<<endl;
    cout<<"name "<<s.name<<endl;
    cout<<"age "<<s.age<<endl;
    cout<<"gender "<<s.gender<<endl;
    */
    //for array
    student sarr[10];
    //input
    for(int i=0;i<3;i++)
    {
        cin.getline(sarr[i].name,100);
        cin>>sarr[i].age;
        cin>>sarr[i].gender;
        cin.get();//as a dummy because cin.getline will read enter
    }
    //output
    for(int i=0;i<3;i++)
    {
        cout<<"students are"<<endl;
        cout<<sarr[i].name<<endl;
        cout<<sarr[i].age<<endl;
        cout<<sarr[i].gender<<endl;
    }
    return 0;
}

