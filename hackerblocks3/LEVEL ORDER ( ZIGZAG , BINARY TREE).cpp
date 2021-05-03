/*
Given a binary tree. Print the zig zag order
i.e print level 1 from left to right, level 2 from right to left and so on.
This means odd levels should get printed from left to right and
even levels should be printed from right to left. Each level should be printed at a new line.

Input Format:
Enter the values of all the nodes in the binary tree in pre-order format
where true suggest the node exists and false suggests it is NULL

Constraints:
None
Output Format:
Display the values in zigzag level order in which each value is separated by a space

Sample Input:
10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false
Sample Output:
10 30 20 40 50 60 73
Time Limit: 4 sec
*/
#include<iostream>
#include<cstring>
#include<queue>
#include<stack>
using namespace std;
struct node
{
    int data;
    node*left;
    node*right;
    node(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
void btree(node** root)
{
    int data;
    char c[5];
    cin>>c;
    if(!strcmp(c,"true"))
    {
        cin>>data;
        (*root)->left=new node(data);
        btree(&((*root)->left));
    }
    cin>>c;
    if(!strcmp(c,"true"))
    {
        cin>>data;
        (*root)->right=new node(data);
        btree(&((*root)->right));
    }
    return;
}

void zigzag(node* root)
{
    if(root==NULL)
    {
        return;
    }
    stack<node*> s;
    queue<node*> q;
    q.push(root);
    node* mark=root+1;
    q.push(mark);
    int n=0;
    while(q.front()!=mark)
    {
        node*top=q.front();
        q.pop();
        if(n%2==0)
        {
            cout<<top->data<<" ";
        }
        else
        {
            s.push(top);
        }
        if(top->left)
        {
            q.push(top->left);
        }
        if(top->right)
        {
            q.push(top->right);
        }
        if(q.front()==mark)
        {
            n++;
            while(!s.empty())
            {
                node*t=s.top();
                cout<<t->data<<" ";
                s.pop();
            }
            q.pop();
            q.push(mark);
        }
    }
}
int main()
{
    int data;
    cin>>data;
    node*root=new node(data);
    btree(&root);
    zigzag(root);
	return 0;
}
