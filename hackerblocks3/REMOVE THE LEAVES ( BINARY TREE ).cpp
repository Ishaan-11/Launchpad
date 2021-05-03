/*
Given a binary tree, remove all the leaves from the tree

Input Format:
Enter the value of the nodes of the tree

Constraints:
None
Output Format:
Display the tree in which all the leaves have been removed in pre-order traversal in the following format:
Left->data => Root->data <= Right->Data
Output END if left or right node is NULL

Sample Input:
50 true 12 true 18 false false false false
Sample Output:
12 => 50 <= END
END => 12 <= END
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
void print(node*root)
{
    if(root->left)
    {
        cout<<root->left->data;
    }
    else
    {
        cout<<"END";
    }
    cout<<" => "<<root->data<<" <= ";
    if(root->right)
    {
        cout<<root->right->data;
    }
    else
    {
        cout<<"END";
    }
    return;
}
void preorder(node*root)
{
    if(root==NULL)
    {
        return;
    }
    print(root);
    cout<<endl;
    preorder(root->left);
    preorder(root->right);
    return;
}
node* del(node*root)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(!(root->left) && !(root->right))
    {
        delete root;
        return NULL;
    }
    root->left=del(root->left);
    root->right=del(root->right);
    return root;;
}
int main()
{
    node*root=BTree();
    root=del(root);
    preorder(root);
	return 0;
}
