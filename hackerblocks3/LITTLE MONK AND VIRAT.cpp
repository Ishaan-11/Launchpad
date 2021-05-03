/*
Little Monk also met who he thinks is the new God of Indian cricket: Virat Kohli.
Now Monk is extremely fond of Kohli -- not just as a T20 player, but a player in all formats.
He loves the statistics involved in Kohli's career.
Little Monk knows that Kohli has played N matches in all three formats of his career, ODI, T20 and
Test Cricket. He wants to show-off his knowledge about Kohli's career so he
decides to answer Q questions asked by Kohli.
Kohli gives the Monk three different arrays with Nnumbers each denoting the runs in the ith ODI match,
ith Test Match and ith T-20 match respectively.
The value of Kohli's ith match would be the sum of his score in the ith T-20 match,
ith Test match and ith ODI match.
Kohli knows that Monk is extremely quick at finding the k th smallest value of all his innings,
so he twists his query a bit.
He asks the Monk to delete the kth smallest value once that is answered by the Monk.
If Kohli comes up with a number k which is greater than the number of matches remaining in Kohli's career,
the Monk should say that the answer is 1 So much complication confuses the Little Monk and
he asks for your help!

Input Format:
The first line contains an integer N,
which denotes the number of matches played by Virat Kohli.
The next three lines contain N integers each denoting the number of runs scored in
ODI, T20 and Test respectively. The next line contains an integer Q,
denoting the number of questions Virat is going to ask.
The next Q lines contain an integer K, denoting the Kth smallest value which the Monk has to answer.

Constraints:
1 ≤ N ≤ 10^6
1 ≤ Ni ≤ 10^9
1 ≤ K ≤ 10^3
1 ≤ Qi ≤ 10^4

Output Format:
Print answer to each query in a new line. In case of an invalid query, print 1.

Sample Input:
5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
3
1
3
11
Sample Output:
3
12
-1
Time Limit: 2 sec
*/
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long a[1000000];
    long long b[1000000];
    long long c[1000000];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>c[i];
    }
    priority_queue<long long,vector<long long>,greater<long long>> p;
    for(int i=0;i<n;i++)
    {
        p.push(a[i]+b[i]+c[i]);
    }
    int q;
    cin>>q;
    for(int Q=0;Q<q;Q++)
    {
        int x;
        cin>>x;
        if(x > p.size())
        {
            cout<<"-1"<<endl;
        }
        else
        {
            long long temp[x-1];
            for(int i=0;i<x-1;i++)
            {
                temp[i]=p.top();
                p.pop();
            }
            cout<<p.top()<<endl;
            p.pop();
            for(int i=x-2;i>=0;i--)
            {
                p.push(temp[i]);
            }
        }
    }
	return 0;
}
