/*
Mike loves hashing.
He decides to create his own hashing technique, so he creates a Hash Function, given as :

int* hash_array(int A[], int n)
{
    int* hash = new int[MAX]; //MAX is the maximum possible value of A[i]
    for(int i=0;i<=MAX;i++) hash[i]=-1; //initialize hash to -1.
    int count = 0;
    for(int i=0;i<n;i++) // Loop through elements of array
    {
        if(hash[A[i]] == -1) // A[i] was not assigned any hash before
        {
            hash[A[i]] = count; // Assigning hash to A[i]
            count++;
            continue;
        }
        for(int j = 0;j<i;j++)
        {
            if(hash[A[j]] > hash[A[i]]) // All the hashes greater than previous hash of A[i] are decremented.
                hash[A[j]]--;
        }
        hash[A[i]] = count - 1; // Assigning a new hash to A[i]
    }
    return hash;
}

You are given an array A. You have to find the Mike's hashes for all the values that
appears in this array.

Input Format:
First line contains a single integer n.
 Next line contains n integers, denoting the elements of array, A.

Constraints:
1<=N<=10^5
1<=A[i]<=10^9

Output Format:
Print k lines, where k is the number of distinct integers in A.
ith line contains integer whose hash value is (i-1).

Sample Input:
4
1 2 1 3
Sample Output:
2
1
3
Explanation:
First iteration : hash[1] = 0. Second iteration : hash[2] = 0 + 1.
Third iteration : hash[2] = hash[2] - 1 = 0, hash[1] = 1. Fourth iteration : hash[3] = 1 + 1 = 2.

Time Limit: 2 sec
*/
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
map<int,int> m;
bool compare(int a,int b)
{
    return m[a]<m[b];
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(m.find(a[i])==m.end())
        {
            v.push_back(a[i]);
        }
        m[a[i]]=i;
    }
    sort(v.begin(),v.end(),compare);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<endl;
    }
	return 0;
}
