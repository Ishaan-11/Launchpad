#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main()
{
    priority_queue<int,vector<int>,greater<int>>p;
    int k;
    vector<int>v;
    cout<<"K "<<endl;
    cin>>k;
    int n,i=0;
    char c;
    cout<<"N "<<endl;
    cin>>n;
    while(n!=-1)
    {
        while(i<k)
        {
            i++;
            p.push(n);
            cin>>n;
            //continue;

        }
        if(n>p.top())
        {
            p.pop();
            p.push(n);
        }
        cout<<"want to print (y/n)"<<endl;
        cin>>c;
        if(c=='y')
        {
            cout<<"k max"<<endl;
            for(int i=0;i<k;i++)
            {
                v.push_back(p.top());
                cout<<p.top()<<" ";
                p.pop();
            }
            cout<<endl;
            for(int i=0;i<k;i++)
            {
                p.push(v[i]);
            }
            v.clear();
        }
        cout<<"N "<<endl;
        cin>>n;
    }
}
