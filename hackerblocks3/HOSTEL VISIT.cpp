/*
Dean of MAIT is going to visit Hostels of MAIT.
As you know that he is a very busy person so he decided to visit only first "K" nearest Hostels.
Hostels are situated in 2D plane.
You are given the coordinates of hostels and you have to answer
the Rocket distance of Kth nearest hostel from origin ( Dean's place ) .

Input Format:
First line of input contains Q Total no. of queries and K There are two types of queries:

first type : 1 x y For query of 1st type,
you came to know about the co-ordinates ( x , y ) of newly constructed hostel.
second type : 2 For query of 2nd type,
you have to output the Rocket distance of Kth nearest hostel till now.

The Dean will always stay at his place ( origin ).
It is gauranted that there will be atleast k queries of type 1 before first query of type 2.

Rocket distance between two points ( x2 , y2 ) and ( x1 , y1 ) is defined as (x2 - x1)2 + (y2 - y1)2

Constraints:
1 < = k < = Q < = 10^5
-10^6 < = x , y < = 10^6

Output Format:
For each query of type 2 output the Rocket distance of Kth nearest hostel from Origin.

Sample Input:
9 3
1 10 10
1 9 9
1 -8 -8
2
1 7 7
2
1 6 6
1 5 5
2
Sample Output:
200
162
98
Time Limit: 2 sec

*/
#include<iostream>
#include<queue>
#define ll long long
using namespace std;
ll rocket_distance(ll x,ll y)
{
    return x*x+y*y;
}
int main()
{
    int q,k;
    cin>>q>>k;
    priority_queue<ll> p;
    for(int i=0;i<q;i++)
    {
        int a;
        cin>>a;
        if(a==1)
        {
            ll x,y;
            cin>>x>>y;
            ll dist=rocket_distance(x,y);
            if(p.size()==k)
            {
                if(dist<p.top())
                {
                    p.pop();
                    p.push(dist);
                }
            }
            else
            {
                p.push(dist);
            }
        }
        else
        {
            cout<<p.top()<<endl;
        }
    }
	return 0;
}
