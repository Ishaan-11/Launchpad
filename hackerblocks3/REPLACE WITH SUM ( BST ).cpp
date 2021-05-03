/*
Replace each node with the sum of all greater nodes in a given BST

Input Format:
Enter the number of nodes N and add N more numbers to the BST

Constraints:
None
Output Format:
Display the resulting tree

Sample Input:
3
2
1
3
Sample Output:
5 => 3 <= 0
END => 5 <= END
END => 0 <= END
Time Limit: 4 sec
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
void add(node** root,int data)
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
        if(it->data < data)
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
void rep(node**root)
{
    static int sum =0;
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
void print(node*root)
{
    if(root->left)
    {
        cout<<root->left->data<<" ";
    }
    else
    {
        cout<<"END"<<" ";
    }
    cout<<"=> "<<root->data<<" <=";
    if(root->right)
    {
        cout<<" "<<root->right->data;
    }
    else
    {
        cout<<" END";
    }
    return;
}
void travel(node*root)
{
    if(root==NULL)
    {
        return;
    }
    print(root);
    cout<<endl;
    travel(root->left);
    travel(root->right);
    return;
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
    rep(&root);
    travel(root);
	return 0;
}
