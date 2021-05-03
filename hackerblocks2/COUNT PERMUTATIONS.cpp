/*
You are given a string of lowercase English letters.
Print all the distinct permutations of this string in lexicographic order.

Input Format:
A string containing lowercase English letters.

Constraints:
1<=|S|<=9
Output Format:
All distinct permutations in lexicographic order(one permutation in each line).

Sample Input:
aba
Sample Output:
aab
aba
baa
*/
#include<iostream>
#include<set>
using namespace std;
set<string> s;
void permutation(char a[10],int i)
{
    if(a[i]=='\0')
    {
        s.insert(a);
    }
    for(int j=i;a[j]!='\0';j++)
    {
        swap(a[j],a[i]);
        permutation(a,i+1);
        swap(a[j],a[i]);
    }
    return;
}
int main()
{
    char a[10];
    cin>>a;
    permutation(a,0);
    set<string>::iterator it;
    for(it=s.begin();it!=s.end();it++)
    {
        cout<<*it<<endl;
    }
	return 0;
}
