#include<iostream>
using namespace std;
struct student
{
    char name[100];
    int age;
    char gender;
    student(char a[100],int age)
    {
        cout<<"i am 3rd constructor"<<endl;
        int i=0;
        while(a[i])
        {
            name[i]=a[i];
            i++;
        }
        name[i]='\0';
        this->age=age;//this pointer(it tells the age is of that object)
        gender='F';
    }
};
int main()
{
    student s3("koko",10);
    cout<<s3.name<<endl;
    cout<<s3.age<<endl;
    cout<<s3.gender<<endl;
    return 0;
}
