/*
Take input of a generic tree using buildtree() function and also take input K the level
at which we need to find the sum.

Input Format:
Tree Input and an integer K

Constraints:
1<K<10
Output Format:
A single line containing the sum

Sample Input:
1 2
2 2
3 0
4 0
5 2
6 0
7 0
2
Sample Output:
20
*/
#include<iostream>
using namespace std;
struct node
{
    int data;
    int childcount;
    node**child;
    node(int data,int childcount)
    {
        this->data=data;
        this->childcount=childcount;
        child=new node*[childcount];
        for(int i=0;i<childcount;i++)
        {
            child[i]=NULL;
        }
    }
};
node* GTree(int data,int childcount)
{
    node*root=new node(data,childcount);
    for(int i=0;i<childcount;i++)
    {
        int d,c;
        cin>>d;
        cin>>c;
        root->child[i]=GTree(d,c);
    }
    return root;
}
int sum(node*root,int k)
{
    static int s=0;
    if(k==0)
    {
        s=s+root->data;
        return s;
    }
    for(int i=0;i<root->childcount;i++)
    {
        s=sum(root->child[i],k-1);
    }
    return s;
}
int main()
{
    int data,childcount;
    cin>>data;
    cin>>childcount;
    node*root=GTree(data,childcount);
    int k;
    cin>>k;
    cout<<sum(root,k);
	return 0;
}
