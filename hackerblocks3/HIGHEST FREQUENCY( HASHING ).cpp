/*
Given an array find the number which comes with maximum frequency.
It must work in O(n) time complexity.

Input Format:
Enter the size of the array N and add N more numbers and store in an array

Output Format:
Display the number with the maximum frequency.

Sample Input:
5
1
2
2
2
3
Sample Output:
2
Time Limit: 4 sec
*/
#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
    int n,a[100000];
    cin>>n;
    unordered_map<int,int> m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        if(m.find(a[i])==m.end())
        {
            m[a[i]]=1;
        }
        else
        {
            m[a[i]]++;
        }
    }
    int max=0,e=0;
    unordered_map<int,int>::iterator it;
    for(it=m.begin();it!=m.end();it++)
    {
        if(it->second>=max)
        {
            max=it->second;
            e=it->first;
        }
    }
    cout<<e;
	return 0;
}
