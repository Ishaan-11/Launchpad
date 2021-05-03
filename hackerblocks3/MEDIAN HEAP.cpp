/*
Write a class which implements following functions(Using Heap)

a. Insert(int nextElement): I can insert numbers into your object using this function.
It should run in O(logn) time, where n is the number of elements inserted so far.

b. int median(): returns the median of the numbers inserted so far. Must work in O(1)

Input Format:
Enter the size of the heap k and insert k more elements to the heap

Output Format:
Display the median of the heap

Sample Input:
4
8
6
7
5
Sample Output:
6 7
Time Limit: 4 sec
*/
#include<iostream>
#include<queue>
using namespace std;
int main()
{
    priority_queue<int> p1;
    priority_queue<int,vector<int>,greater<int>>p2;
    int n,median,x;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        if(p1.size()>p2.size())
        {
            if(n<median)
            {
                p2.push(p1.top());
                p1.pop();
                p1.push(x);
            }
            else
            {
                p2.push(x);
            }
            median=(p1.top()+p2.top())/2;
        }
        else if(p1.size()<p2.size())
        {
            if(n<median)
            {
                p1.push(x);
            }
            else
            {
                p1.push(p2.top());
                p2.pop();
                p2.push(x);
            }
            median=(p1.top()+p2.top())/2;
        }
        else
        {
            if(n<median)
            {
                p1.push(x);
                median=p1.top();
            }
            else
            {
                p2.push(x);
                median=p2.top();
            }
        }
    }
    if(p1.size()==p2.size())
    {
        cout<<p1.top()<<endl<<p2.top()<<endl;
    }
    else if(p1.size()>p2.size())
    {
        cout<<p1.top()<<endl;
    }
    else
    {
        cout<<p2.top()<<endl;
    }
	return 0;
}
