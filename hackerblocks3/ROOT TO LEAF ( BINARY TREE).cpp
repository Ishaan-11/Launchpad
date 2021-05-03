/*
Given a binary tree and a number k,
print out all root to leaf paths where the sum of all nodes value is same as the given number.

Input Format:
First line contains the values of all the nodes in the binary tree in pre-order format where
true suggest the node exists and false suggests it is NULL. Second line contains the number k.

Constraints:
None
Output Format:
Display the root to leaf path whose sum is equal to k.

Sample Input:
10 true 20 true 30 false false true 50 false false true 40 true 60 false false true 73 false false
60
Sample Output:
10 20 30
Explanation:
The given tree is in pre order traversal. So convert it into binary tree and check root to leaf path sum.

Time Limit: 4 sec
*/
#include<iostream>
#include<cstring>
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
node* BTree()
{
    int data;
    cin>>data;
    node*root=new node(data);
    char c[5];
    cin>>c;
    if(!strcmp(c,"true"))
    {
        root->left=BTree();
    }
    cin>>c;
    if(!strcmp(c,"true"))
    {
        root->right=BTree();
    }
    return root;
}
int total(int a[],int cl)
{
    int sum=0;
    for(int i=0;i<=cl;i++)
    {
        sum+=a[i];
    }
    return sum;
}
void print(int a[],int cl)
{
    for(int i=0;i<=cl;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return;
}
void RTL(node*root,int k,int a[1000],int cl)
{
    if(root==NULL)
    {
        return;
    }
    a[cl]=root->data;
    if(root->left==NULL && root->right==NULL)
    {
        int sum=total(a,cl);
        if(sum==k)
        {
            print(a,cl);
        }
    }
    RTL(root->left,k,a,cl+1);
    RTL(root->right,k,a,cl+1);
    return;
}
int main()
{
    node*root=BTree();
    int k;
    int a[1000];
    cin>>k;
    RTL(root,k,a,0);
	return 0;
}
