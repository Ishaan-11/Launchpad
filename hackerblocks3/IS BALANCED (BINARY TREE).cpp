/*
Given a Binary tree check if it is balanced
i.e. depth of the left and right sub-trees of every node differ by 1 or less.

Input Format:
Enter the values of all the nodes in the binary tree in pre-order format where
true suggest the node exists and false suggests it is NULL

Constraints:
None
Output Format:
Display the Boolean result

Sample Input:
10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false
Sample Output:
true
Time Limit: 4 sec
*/
#include<iostream>
#include<queue>
#include<cstring>
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
    char check[5];
    cin>>check;
    if(!strcmp(check,"true"))
    {
        cin>>data;
        node* left=new node(data);
        (*root)->left=left;
        btree(&left);
    }
    cin>>check;
    if(!strcmp(check,"true"))
    {
        cin>>data;
        node* right=new node(data);
        (*root)->right=right;
        btree(&right);
    }
    return;
};
void levelorder(node* root)
{
    if(root==NULL)
    {
        return;
    }
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        node* top=q.front();
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
    }
    return;
}
int max(int a,int b)
{
    if(a>b)
    {
        return a;
    }
    return b;
}
pair<bool,int> balance(node* root)
{
    if(root==NULL)
    {
        pair<bool,int> p;
        p.first=true;
        p.second=0;
        return p;
    }
    pair<bool,int> l=balance(root->left);
    pair<bool,int> r=balance(root->right);
    pair<bool,int> p;
    if(((l.second-r.second)>1) ||((l.second-r.second)<-1))
    {
        p.first=false;
    }
    else
    {
        p.first=true;
    }
    p.second=max(l.second,r.second)+1;
    return p;
}
int main()
{
    int data;
    cin>>data;
    node* root=new node(data);
    btree(&root);
    //levelorder(root);
    pair<bool,int> p=balance(root);
    if(p.first)
    {
        cout<<"true";
    }
    else
    {
        cout<<"false";
    }
	return 0;
}
