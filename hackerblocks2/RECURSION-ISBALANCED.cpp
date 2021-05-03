/*
ECURSION-ISBALANCED
Take as input str, a string. The string is a mathematical expression e.g. “[a + {b + (c + d) + e} + f]”. Write a recursive function which tests if the brackets in expression are balanced or not and returns a Boolean value. Print the value returned.

Input Format:
Enter the string

Constraints:
None
Output Format:
Display the boolean result

Sample Input:
[a + {b + (c + d) + e} + f]
Sample Output:
true
*/
#include<iostream>
using namespace std;
template<typename T>
struct node
{
    T data;
    node<T>* next;
};
template<typename T>
struct stack
{
    private:
    node<T>*head;
    int n;
    public:
    stack()
    {
        head=NULL;
        n=0;
    }
    int size()
    {
        return n;
    }
    bool isempty()
    {
        if(head==NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void push(T data)
    {
        node<T>* temp=new node<T>();
        temp->data=data;
        temp->next=head;
        head=temp;
        n++;
        return;
    }
    void pop()
    {
        if(isempty())
        {
            return;
        }
        node<T>*it=head;
        head=head->next;
        delete it;
        n--;
        return;
    }
    T top()
    {
        if(isempty())
        {
            return NULL;
        }
        return (head->data);
    }
};
int main()
{
    stack<char> s;
    char a[1000000];
    cin.getline(a,1000000);
    for(int i=0;a[i]!='\0';i++)
    {
        if(a[i]=='(' || a[i]=='{' || a[i]=='[')
        {
            s.push(a[i]);
        }
        /*if(s.isempty())
        {
            cout<<"false";
            return 0;
        }*/
        char top=s.top();
        if((a[i]==')' && top=='(') || (a[i]=='}' && top=='{') || (a[i]==']' && top=='['))
        {
            s.pop();
        }
        //cout<<"false";
        //return 0;
    }
    if(s.isempty())
    {
        cout<<"true";
    }
    else
    {
        cout<<"false";
    }
	return 0;
}
//without stack
/*
#include<iostream>
using namespace std;
bool paren(char a[],int i,char b[],int j)
{
    if(a[i]=='\0')
    {
        if(b[j-1]!='\0')
        {
            return false;
        }
        return true;
    }
    else if(a[i]=='['||a[i]=='{'||a[i]=='(')
    {
        b[j]=a[i];
        //cout<<b<<" ";
        return paren(a,i+1,b,j+1);
    }
    else if((a[i]==']'&&b[j-1]!='[')||(a[i]=='}'&&b[j-1]!='{')||(a[i]==')'&&b[j-1]!='('))
    {
        //cout<<a[i]<<b[j-1]<<".";
        return false;
    }
    else if((a[i]==']'&&b[j-1]=='[')||(a[i]=='}'&&b[j-1]=='{')||(a[i]==')'&&b[j-1]=='('))
    {   b[j-1]='\0';
        //cout<<b<<" ";
        return paren(a,i+1,b,j-1);
    }
    else
    {
        return paren(a,i+1,b,j);
    }
}
int main()
{
    char a[1000],b[1000];
    cin.getline(a,1000);
    //cout<<b;
    if(paren(a,0,b,0))
    {
        cout<<"true";
    }
    else
    {
        cout<<"false";
    }
	return 0;
}
*/
