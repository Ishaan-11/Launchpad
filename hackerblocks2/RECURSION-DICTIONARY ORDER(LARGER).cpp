/*
Take as input str, a string.
Write a recursive function which prints all the words possible by
rearranging the characters of this string which are in dictionary order larger than the given string

Input Format:
Enter a string

Constraints:
None

Output Format:
Display all the words larger than the string entered in separate lines

Sample Input:
cab

Sample Output:
cba
*/
#include<iostream>
#include<cstring>
using namespace std;
void permutation(string a,int i,string b,int l)
{
    if(i>l)
    {
        if(a>b)
        {
            cout<<a<<endl;
        }
        return;
    }
    for(int j=i;j<=l;j++)
    {
        swap(a[i],a[j]);
        permutation(a,i+1,b,l);
        //swap(a[i],a[j]);
    }
    return;
}
int main()
{
    string a;
    cin>>a;
    permutation(a,0,a,a.length()-1);
	return 0;
}
/*
#include<iostream>
#include<cstring>
using namespace std;
bool comp(char a[],char b[])
{
    for(int i=0;a[i]!='\0';i++)
    {
        if(b[i]<a[i])
        {
            return true;
        }
        else if(b[i]>a[i])
        {
            return false;
        }
    }
    return false;
}
void shift2(char a[],int i,int j)
{
    char temp=a[i];
    for(int k=0;k<j-i;k++)
    {
        a[i+k]=a[i+1+k];
    }
    a[j]=temp;
}
void shift1(char a[],int i,int j)
{
    char temp=a[j];
    for(int k=0;k<j-i;k++)
    {
        a[j-k]=a[j-1-k];
    }
    a[i]=temp;
}
void perm(char a[100],char b[100],int i)
{
    if(a[i]=='\0')
    {
        if(comp(a,b))
        {
            cout<<a<<endl;
        }
        return;
    }
    for(int j=i;a[j]!='\0';j++)
    {
        shift1(a,i,j);//j ki value i me
        perm(a,b,i+1);
        shift2(a,i,j);//i ki value j me
    }
    return;
}
int main()
{
    char a[100],b[100];
    cin>>a;
    int i;
    for(i=0;a[i]!='\0';i++)
    {
        b[i]=a[i];
    }
    b[i]='\0';
    perm(a,b,0);
	return 0;
}
*/
