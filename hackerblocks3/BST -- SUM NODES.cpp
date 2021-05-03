/*
Replace each node with the sum of all greater nodes in a given BST

Input Format:
Take input of BST unitl -1 is given

Constraints:
1<no of nodes <1000
Output Format:
Print level order BST.

Sample Input:
4
2
5
1
3
-1
Sample Output:
5
12 0
14 9
*/
#include<iostream>
#include<queue>
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
void add(node**root,int data)
{
    if(*root==NULL)
    {
        *root=new node(data);
        return;
    }
    node*it=*root;
    node*temp=new node(data);
    while(it)
    {
        if(it->data<data)
        {
            if(it->right==NULL)
            {
                it->right=temp;
                return;
            }
            it=it->right;
        }
        else
        {
            if(it->left==NULL)
            {
                it->left=temp;
                return;
            }
            it=it->left;
        }
    }
    return;
}
void levelorder(node*root)
{
    if(root==NULL)
    {
        return;
    }
    queue<node*>q;
    q.push(root);
    node*mark=(root+1);
    q.push(mark);
    while(q.front()!=mark)
    {
        node*top=q.front();
        cout<<top->data<<" ";
        q.pop();
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
            cout<<endl;
            q.pop();
            q.push(mark);
        }
    }
    return;
}
void rep(node**root)
{
    static int sum=0;
    if(*root==NULL)
    {
        return;
    }
    rep(&((*root)->right));
    sum=sum+(*root)->data;
    (*root)->data=sum-(*root)->data;
    rep(&((*root)->left));
    return;
}
int main()
{
    int n;
    node*root=NULL;
    cin>>n;
    while(n!=-1)
    {
        add(&root,n);
        cin>>n;
    }
    rep(&root);
    levelorder(root);
	return 0;
}
