/*
Given two trees check if they are structurally identically


Input Format:
Enter the values of all the nodes in the binary tree in pre-order format where
true suggest the node exists and false suggests it is NULL

Constraints:
None
Output Format:
Display the Boolean result

Sample Input:
10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false
10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false
Sample Output:
true
Time Limit: 4 sec
*/
#include<iostream>
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
void btree(node**root)
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
bool compare(node* root1,node* root2)
{
    if(root1==NULL && root2==NULL)
    {
        return true;
    }
    if(root1==NULL)
    {
        return false;
    }
    if(root2==NULL)
    {
        return false;
    }
    bool l=compare(root1->left,root2->left);
    bool r=compare(root1->right,root2->right);
    return (l && r);
}
int main()
{
    int data;
    cin>>data;
    node*root1=new node(data);
    btree(&root1);
    cin>>data;
    node*root2=new node(data);
    btree(&root2);
    if(compare(root1,root2))
    {
        cout<<"true";
    }
    else
    {
        cout<<"false";
    }
	return 0;
}
