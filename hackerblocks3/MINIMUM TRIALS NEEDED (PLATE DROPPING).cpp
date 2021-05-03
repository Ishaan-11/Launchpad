/*
MINIMUM TRIALS NEEDED (PLATE DROPPING)
Aakash has K identical plates and N floors.
He needs to find the lowest floor at which the plate will break down aka critical floor.
However, he doesn't like climbing stairs again and again. So he decided to take your help.
Help him design a strategy that would tell him the minimum no of trials he need to perform for
knowing the critical floor.

Assume that plate will only break at critical floor and floors higher than that.

_Hint :
_Recursion tells u what u intend to calculate._
Test case 3 is only for students who think that the test cases are easy.

Input Format:
The first line contains T, the number of test cases.
Next T line follows 2 space separated integers, first being the number of plates K,
next being the number of floors N.

Constraints:
0 < T < 10

0 < K < 2

0 < N < 10

Output Format:
T lines of required answer

Sample Input:
1
2 3
Sample Output:
2
Explanation:
Aakash can start dropping plates from floor 1, 2 or 3.

Consider floor 1 :

If the plate breaks, critical floor is floor 1 else he moves to floor 2 and repeat the process.
By this method minimum no of trials to know the critical floor are 3.

Consider he starts with 2nd floor.

Now if the plate breaks, the number of floors left to be checked is 1, floor 1.
If it doesn't break, then floors to be tested is floor 3. In both the cases the number of trials are 2.
So Akash will start from floor 2

Time Limit: 1 sec
*/
#include<iostream>
#include<cstring>
#include<climits>
using namespace std;
int dp[1005][1005];
int trials(int plates,int floors)
{
    if(floors==0 || floors==1)
    {
        return floors;
    }
    if(plates==1)
    {
        return floors;
    }
    if(dp[plates][floors]!=-1)
    {
        return dp[plates][floors];
    }
    int ans=INT_MAX;
    for(int i=1;i<=floors;i++)
    {
        int cur=max(trials(plates-1,i-1),trials(plates,floors-i));
        if(cur<ans)
        {
            ans=cur;
        }
    }
    return dp[plates][floors]=1+ans;
}
int main()
{
    int T;
    cin>>T;
    for(int t=0;t<T;t++)
    {
        memset(dp,-1,sizeof(dp));
        int plates,floors;
        cin>>plates>>floors;
        cout<<trials(plates,floors)<<endl;
    }
	return 0;
}
