/*
Given a Binary tree, write code to create a separate array list for each level.
You should return an arraylist of arraylist.

Input Format:
Enter the values of all the nodes in the binary tree in pre-order format where
true suggest the node exists and false suggests it is NULL

Constraints:
None
Output Format:
Display the resulting arraylist of arraylist according to given sample examples.

Sample Input:
50 true 12 true 18 false false true 13 false false false
Sample Output:
[[50], [12], [18, 13]]

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
void array(node*root)
{
    if(root==NULL)
    {
        return;
    }
    queue<node*> q;
    node* mark=root+1;
    q.push(root);
    q.push(mark);
    cout<<"[[";
    while(q.front()!=mark)
    {
        node*top=q.front();
        q.pop();
        cout<<top->data;
        if(q.front()!=mark)
        {
            cout<<", ";
        }
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
            q.pop();
            q.push(mark);
            if(q.front()==mark)
            {
                cout<<"]]";
            }
            else
            {
                cout<<"], [";
            }
        }
    }
    return;
}
int main()
{
    int data;
    cin>>data;
    node* root=new node(data);
    btree(&root);
    array(root);
	return 0;
}
