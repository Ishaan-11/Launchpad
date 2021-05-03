#include<iostream>
using namespace std;
struct student
{
    char name[100];
    int age;
    char gender;
    student()
    {
        cout<<"i am constructor"<<endl;
        age=10;
    }
    student(char a[100])
    {
        cout<<"i am 2nd constructor"<<endl;
        int i=0;
        while(a[i])
        {
            name[i]=a[i];
            i++;
        }
        name[i]='\0';
        age=0;
        gender='M';
    }
    student(char a[100],int x)
    {
        cout<<"i am 3rd constructor"<<endl;
        int i=0;
        while(a[i])
        {
            name[i]=a[i];
            i++;
        }
        name[i]='\0';
        age=x;
        gender='F';
    }
};
int main()
{
    student s("ram");
    student s3("koko",10);
    student s1;
    //student s,s2,s3,s4;
    cout<<s3.name<<endl;
    cout<<s3.age<<endl;
    cout<<s3.gender<<endl;
    return 0;
}
