/*
For each node in a binary search tree, create a new duplicate node,
and insert the duplicate as the left child of the original node.

Input Format:
Enter the number of nodes N and add N more numbers to the BST

Constraints:
None
Output Format:
Display the tree

Sample Input:
3
2
1
3
Sample Output:
2 => 2 <= 3
1 => 2 <= END
1 => 1 <= END
END => 1 <= END
3 => 3 <=END
END => 3 <=END
Time Limit: 4 sec
*/
#include<iostream>
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
    node*temp=new node(data);
    node*it=*root;
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
node* dup(node*root)
{
    if(root==NULL)
    {
        return NULL;
    }
    root->left=dup(root->left);
    root->right=dup(root->right);
    node*temp=new node(root->data);
    temp->left=root->left;
    root->left=temp;
    return root;
}
int main()
{
    int n;
    cin>>n;
    node*root=NULL;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        add(&root,x);
    }
    root=dup(root);
    preorder(root);
	return 0;
}
