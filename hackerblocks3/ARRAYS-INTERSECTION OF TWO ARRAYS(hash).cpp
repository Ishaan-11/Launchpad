/*
Take as input N, the size of array. Take N more inputs and store that in an array.
Take N more inputs and store that in another array.
Write a function which gives the intersection of two arrays in an ArrayList of integers and
Print the ArrayList.

Constraints:
Length of Arrays should be between 1 to 1000.

Sample Input:
7
1 2 3 1 2 4 1
2 1 3 1 5 2 2
Sample Output:
[1, 1, 2, 2, 3]
Explanation:
Check which integer is present in both the arrays and add them in an Arraylist .
Print ArrayList as the ans.

*/
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    map<int,int>m;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        m[x]++;
    }
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if(m.find(x)!=m.end())
        {
            m[x]--;
            if(m[x]>=0)
            {
                v.push_back(x);
            }
        }
    }
    sort(v.begin(),v.end());
    cout<<"[";
    for(int i=0;i<v.size();i++)
    {
        if(i==v.size()-1)
        {
            cout<<v[i];
        }
        else
        {
            cout<<v[i]<<", ";
        }
    }
    cout<<"]";
	return 0;
}
