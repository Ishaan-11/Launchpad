#include<iostream>
using namespace std;
struct location
{
    char street[100];
    int pincode;
    location()
    {
        cout<<"location constructure"<<endl;
        street[0]='a';
        street[1]='b';
        street[2]='\0';
        pincode=1234;
    }
};
struct student
{
    char name[100];
    int age;
    char gender;
    location *adr;
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
        adr=0;
    }
};
void print(student s)
{
    cout<<s.name<<endl;
    cout<<s.age<<endl;
    cout<<s.gender<<endl;
    cout<<(*(s.adr)).street<<endl;
    //cout<<(s.adr)->street<<endl;
    cout<<(*(s.adr)).pincode<<endl;
    //cout<<(s.adr)->pincode<<endl;
}
int main()
{
    student s("ram");
    /*
    location a;
    s.adr=&a;
    cout<<a.street<<endl;
    cout<<a.pincode<<endl;
    */
    location *a=new location;
    s.adr=a;
    cout<<(*a).street<<endl;
    //cout<<a->street<<endl;
    cout<<(*a).pincode<<endl;
    //cout<<a->pincode<<endl;
    print(s);
    return 0;
}
