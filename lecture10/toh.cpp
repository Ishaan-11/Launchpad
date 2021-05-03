#include<iostream>
using namespace std;
void toh(int n,char source,char helper,char destination)
{
    if(n==1)
    {
        cout<<"move "<<source<<" to "<<destination<<endl;
        return;
    }
    toh(n-1,source,destination,helper);
    {
        cout<<"move "<<source<<" to "<<destination<<endl;
    }
    toh(n-1,helper,source,destination);
    return;
}
int main()
{
    toh(3,'A','B','C');
    return 0;
}
