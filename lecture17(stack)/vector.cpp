#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int>v;
    cout<<v.size()<<endl;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    cout<<v.size()<<endl;
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    v[2]=60;
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    v.pop_back();
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl<<v[2];
    return 0;
}
