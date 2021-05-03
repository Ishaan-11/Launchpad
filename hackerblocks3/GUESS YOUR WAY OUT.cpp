/*
Amr bought a new video game "Guess Your Way Out!".
The goal of the game is to find an exit from the maze that looks like a perfect binary tree of height h.
The player is initially standing at the root of the tree and the exit from
the tree is located at some leaf node.

Let's index all the leaf nodes from the left to the right from 1 to 2h.
The exit is located at some node n where 1≤n≤2h,
the player doesn't know where the exit is so he has to guess his way out!

Amr follows simple algorithm to choose the path.
Let's consider infinite command string "LRLRLRLRL…" (consisting of alternating characters 'L' and 'R').
Amr sequentially executes the characters of the string using following rules:

Character 'L' means "go to the left child of the current node";
Character 'R' means "go to the right child of the current node";
If the destination node is already visited, Amr skips current command,
otherwise he moves to the destination node;
If Amr skipped two consecutive commands,
he goes back to the parent of the current node before executing next command;
If he reached a leaf node that is not the exit, he returns to the parent of the current node;
If he reaches an exit, the game is finished.
Now Amr wonders, if he follows this algorithm,
how many nodes he is going to visit before reaching the exit?

Input Format:
The first line consists of number of test cases T. Each test case consists of two integers h and n.

Constraints:
1 <= T <= 50.
1 <= h <= 50.
1 <= n <= 2^h.

Output Format:
The answer for every test case in new line

Sample Input:
5
3 8
2 3
1 2
2 4
3 6
Sample Output:
14
5
2
6
10
Time Limit: 2 sec
*/
#include<iostream>
#include<math.h>
#define ll long long
using namespace std;
ll ans=0;
void guess(int h,int e,bool dir)
{
    if(h==0)
    {
        return;
    }
    ll lim=ceil(pow(2,h-1));
    if(e<=lim)//left
    {
        if(dir==0)//left
        {
            ans++;
            guess(h-1,e,!dir);
            return;
        }
        else//right
        {
            ans+=ceil(pow(2,h));
            guess(h-1,e,dir);
            return;
        }
    }
    else//right
    {
        if(dir==0)//left
        {
            ans+=ceil(pow(2,h));
            guess(h-1,e-ceil(pow(2,h-1)),dir);
            return;
        }
        else//right
        {
            ans++;
            guess(h-1,e-ceil(pow(2,h-1)),!dir);
            return;
        }
    }
    return;
}
int main()
{
    int T;
    cin>>T;
    for(int t=0;t<T;t++)
    {
        int h,e;
        cin>>h>>e;
        ans=0;
        guess(h,e,0);//0 for left and 1 for right
        cout<<ans<<endl;
    }
	return 0;
}
