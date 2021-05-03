/*
Implement a stack such that the operation findMid() is performed in linear time complexity
i.e. in O(1). findMid() is a function which returns the middle element of the stack.

Input Format:
First line contains the number of elements in stack,N. Next line contains N elements of stack.

Constraints:
0<N<10^9
Output Format:
Print the middle element of the stack.

Sample Input:
7
1 2 3 4 5 6 7
Sample Output:
4
Explanation:
In the given case 4 is the middle element of the stack.
*/
#include<iostream>
#include<vector>
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
        return;
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
int findmid(stack s)
{
    if(s.empty())
    {
        return -1;
    }
    int m=s.size()/2;
    for(int i=0;i<m;i++)
    {
        s.pop();
    }
    return s.top();
}
int main()
{
    stack s;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        s.push(x);
    }
    cout<<findmid(s);
	return 0;
}
//correct way
/*
#include<iostream>
using namespace std;
struct node
{
    int data;
    node*next;
    node*prev;
    node(int data)
    {
        this->data=data;
        next=NULL;
        prev=NULL;
    }
};
struct stack
{
    private:
    node*head;
    node*mid;
    int n=0;
    public:
    stack()
    {
        head=0;
        mid=0;
        n=0;
    }
    int size()
    {
        return n;
    }
    bool empty()
    {
        return head==NULL;
    }
    void push(int data)
    {
        node*temp=new node(data);
        n++;
        if(empty())
        {
            head=temp;
            mid=temp;
            return;
        }
        temp->next=head;
        head->prev=temp;
        head=temp;
        if(size()%2!=0)
        {
            mid=mid->prev;
        }
        return;
    }
    void pop()
    {
        if(!empty())
        {
            node*it=head;
            head=head->next;
            n--;
            delete it;
            if(size()%2==0)
            {
                if(size()==0)
                {
                    mid=NULL;
                    return;
                }
                mid=mid->next;
            }
        }
    }
    int midele()
    {
        if(empty())
        {
            return -1;
        }
        return mid->data;
    }
};
int main()
{
    int n,x;
    cin>>n;
    stack s;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        s.push(x);
    }
    s.pop();
    cout<<s.midele();
	return 0;
}
*/
