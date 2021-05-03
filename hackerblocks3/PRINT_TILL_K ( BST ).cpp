/*

Given a tree and a node of tree, print all nodes which are at distance k from the given node.

Input Format:
Enter the number of nodes N and add N more numbers to the BST.
Then enter the target number and value of k.

Constraints:
None

Output Format:
Display all the nodes which are at a distance k in a new line

Sample Input:
4
1
2
3
4
4
2
Sample Output:
2
Time Limit: 4 sec
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> v;
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
void addelement(node**root,int data)
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
            if(!it->right)
            {
                it->right=temp;
                return;
            }
            it=it->right;
        }
        else
        {
            if(!it->left)
            {
                it->left=temp;
                return;
            }
            it=it->left;
        }
    }
    return;
}
void print_down(node*root,int k)
{
    if(root==NULL)
    {
        return;
    }
    if(k==0)
    {
        v.push_back(root->data);
        return;
    }
    print_down(root->left,k-1);
    print_down(root->right,k-1);
    return;
}
int print_k(node*root,int k,int target)
{
    if(root==NULL)
    {
        return -1;
    }
    if(root->data==target)
    {
        print_down(root,k);
        return 0;
    }
    int l=print_k(root->left,k,target);
    if(l!=-1)
    {
        if(l+1==k)
        {
            v.push_back(root->data);
        }
        else
        {
            print_down(root->right,k-l-2);
        }
        return l+1;
    }
    int r=print_k(root->right,k,target);
    if(r!=-1)
    {
        if(r+1==k)
        {
            v.push_back(root->data);
        }
        else
        {
            print_down(root->left,k-r-2);
        }
        return r+1;
    }
    return -1;
}
int main()
{
    int n;
    cin>>n;
    node*root=0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        addelement(&root,x);
    }
    int target,k;
    cin>>target>>k;
    print_k(root,k,target);
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<endl;
    }
    v.clear();
	return 0;
}
