/*
UNLOCK
Shekhar is a bomb defusal specialist.
He once encountered a bomb that can be defused only by a secret code.
He is given a number N and a number K.
 And he is also given permutation of first N natural numbers .
 The defusal code is the largest permutation possible by doing exactly K
 swaps among a pair of the given permutation.
 Help him to find the final permutation.

Input Format:
First line contains ​an integer N and an integer k.
The next line contains N space separated integers denoting the given permutation.

Constraints:
1 <= n <= 10^5 1<= K <= 10^9

Output Format:
The final permutation of the numbers with every number separated by a space with other number.

Sample Input:
5 2
3 4 1 2 5
Sample Output:
5 4 3 2 1
Explanation:
First we can swap 5 with 3 which gives us 5 4 1 2 3 and
then we can swap 3 and 1 which gives us 5 4 3 2 1.

Time Limit: 2 sec
*/
#include<iostream>
#include<map>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    map<int,int> m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        m[a[i]]=i;
    }
    int max=n;
    int index=0;
    while(k>0 && index<n)
    {
        map<int,int>::iterator it=m.find(max-index);
        int curmax_i=it->second;
        if(curmax_i==index)
        {
            index++;
            continue;
        }
        else
        {
            m.erase(a[curmax_i]);
            m.erase(a[index]);
            int temp=a[curmax_i];
            a[curmax_i]=a[index];
            a[index]=temp;
            m[a[index]]=index;
            m[a[curmax_i]]=curmax_i;
            index++;
            k--;
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
	return 0;
}
//find the index 0f max number and swap
/*
#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
    int n,k;
    int a[100000];
    unordered_map<int,int>m;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        m[a[i]]=i;
    }
    for(int i=0;i<n;i++)
    {
        if(k==0)
        {
            break;
        }
        if(a[i]!=n-i)
        {
            int index=m[n-i];
            m[n-i]=i;
            m[a[i]]=index;
            swap(a[i],a[index]);
            k--;
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
	return 0;
}
*/
