/*
Google Tower of Hanoi.

a. Write a recursive function
which prints the steps required to solve the tower of Hanoi problem for N discs.

b. Write a recursive function
which returns number of steps required to solve the tower of Hanoi problem for N discs.

Input Format:
Enter the number of discs

Constraints:
None
Output Format:
Display the steps required to solve the tower and also print the total number of steps required

Sample Input:
2
Sample Output:
Move 1th disc from T1 to T3
Move 2th disc from T1 to T2
Move 1th disc from T3 to T2
3
*/
#include <iostream>
using namespace std;
void toh(int n,char source[3],char destination[3],char helper[3])
{
    if(n==1)
    {
        cout<<"Move "<<n<<"th disc from "<<source<<" to "<<destination<<endl;
        return;
    }
    toh(n-1,source,helper,destination);
    cout<<"Move "<<n<<"th disc from "<<source<<" to "<<destination<<endl;
    toh(n-1,helper,destination,source);
    return;
}
int toh1(int n,char source[3],char destination[3],char helper[3])
{
    int c=0;
    if(n==1)
    {
        return 1;
    }
    c=c+toh1(n-1,source,helper,destination);
    c++;
    c=c+toh1(n-1,helper,destination,source);
    return c;
}
int main()
{
    int n;
    cin>>n;
    toh(n,"T1","T2","T3");
    cout<<toh1(n,"T1","T2","T3");
    return 0;
}
