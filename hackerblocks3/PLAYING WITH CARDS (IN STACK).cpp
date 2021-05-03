/*
You are at a casino.
There are N stacked cards on pile . Each card has a number written on it.
Then there will be Q iterations.
In ith iteration, you start picking up the cards in Ai-1th pile from the top one by one and
check whether the number written on the card is divisible by the ith prime number.
If the number is divisible, you stack that card on pile Bi. Otherwise, you stack that card on pile Ai.
After Q iterations, cards can only be on pile B1, B2, B3, . . . BQ, AQ .
Output numbers on these cards from top to bottom of each piles in order of B1, B2, B3, . . . BQ, AQ .

Input Format:
First line contains N and Q.
The next line contains N space separated integers representing the initial pile of cards i.e., A0.
The leftmost value represents the bottom plate of the pile.

Constraints:
N < 10^5
Output Format:
Output N lines, each line containing the number written on the card.

Sample Input:
5 1
3 4 7 6 5
Sample Output:
4
6
3
7
5
Explanation:
Initially:

A0 = [3, 4, 7, 6, 5]<-TOP

After 1st iteration:

A0 = []<-TOP

A1 = [5, 7, 3]<-TOP

B1 = [6, 4]<-TOP

Now first print B1 from top to bottom then A1 from top to bottom.
*/
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
struct stack
{
    private:
    int data;
    vector<int> v;
    public:
    int size()
    {
        return v.size();
    }
    bool empty()
    {
        return v.size()==0;
    }
    void push(int data)
    {
        v.push_back(data);
    }
    void pop()
    {
        if(empty())
        {
            return;
        }
        v.pop_back();
        return;
    }
    int top()
    {
        if(empty())
        {
            return -1;
        }
        return v[v.size()-1];
    }
};
int prime(int q)
{
    int x=0;
    for(int i=2;i<INT_MAX;i++)
    {
        int a=0;
        for(int j=2;j<i;j++)
        {
            if(i%j==0)
            {
                a=1;
                break;
            }
        }
        if(a==0)
        {
            x++;
        }
        if(q==x)
        {
            return i;
        }
    }
}
void copy(stack &a,stack &s)
{
    if(a.empty())
    {
        return;
    }
    int top=a.top();
    a.pop();
    copy(a,s);
    s.push(top);
    return;
}
int main()
{
    stack s;
    int n;
    cin>>n;
    int q;
    cin>>q;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        s.push(x);
    }
    if(q==0)
    {
        while(!s.empty())
        {
            cout<<s.top()<<endl;
            s.pop();
        }
    }
    for(int p=1;p<=q;p++)
    {
        stack a;
        stack b;
        while(!s.empty())
        {
            if(s.top()%prime(p)==0)
            {
                b.push(s.top());
                s.pop();
            }
            else
            {
                a.push(s.top());
                s.pop();
            }
        }
        while(!b.empty())
        {
            cout<<b.top()<<endl;
            b.pop();
        }
        copy(a,s);
    }
    //stack a;
   // copy(s,a);
    while(!s.empty())
    {
        cout<<s.top()<<endl;
        s.pop();
    }
   // cout<<prime(4);
	return 0;
}
