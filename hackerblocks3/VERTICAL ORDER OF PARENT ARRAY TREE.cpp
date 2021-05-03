/*
You are given an array that represents a tree in such a way that array indexes are values in tree nodes
and array values give the parent node of that particular index (or node) .
The value of the root node index would always be -1.
Your work is to construct that tree and print vertical order traversal.

Input Format:
First line contains integer t as number of test cases.
Each test case contains two lines.
 line contains an integer n which is length of the array and
 second line contains n space separated integer.

Constraints:
1 < t < 20
1< n < 50
Output Format:
For each test case print vertical order traversal of the tree.

Sample Input:
1
7
-1 0 0 1 1 3 5
Sample Output:
6
5
3
1
0 4
2
*/
#include<iostream>
#include<climits>
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
int find(int a[],int n,int data)
{
    for(int i=0;i<n;i++)
    {
        if(a[i]==data)
        {
            a[i]=INT_MIN;
            return i;
        }
    }
    return -2;
}
node* tree(int a[],int n,int data)
{
    int x=find(a,n,data);
    if(x==-2)
    {
        return NULL;
    }
    node*root=new node(x);
    root->left=tree(a,n,x);
    root->right=tree(a,n,x);
    return root;
}
pair<int,int>range(node*root,int m)
{
    if(root==NULL)
    {
        pair<int,int>p;
        p.first=0;
        p.second=0;
        return p;
    }
    pair<int,int>l=range(root->left,m-1);
    pair<int,int>r=range(root->right,m+1);
    pair<int,int>p;
    p.first=min(m,min(l.first,r.first));
    p.second=max(m,max(l.second,r.second));
    return p;
}
void print(node*root,int m,int j)
{
    if(root==NULL)
    {
        return;
    }
    if(m==j)
    {
        cout<<root->data<<" ";
    }
    print(root->left,m-1,j);
    print(root->right,m+1,j);
    return;
}
int main()
{
    int t;
    cin>>t;
    int a[50];
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;
        for(int j=0;j<n;j++)
        {
            cin>>a[j];
        }
        node*root=tree(a,n,-1);
        pair<int,int>p=range(root,0);
        //cout<<p.first<<" "<<p.second;
        for(int j=p.first;j<=p.second;j++)
        {
            print(root,0,j);
            cout<<endl;
        }
    }
	return 0;
}
