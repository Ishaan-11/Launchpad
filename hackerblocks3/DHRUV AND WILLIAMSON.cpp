/*

Dhruv is a huge cricket fan,
so he decides that he'll meet his five favorite cricketers in this problem-set of heaps.
And he'll try to impress them. The first cricketer he wants to impress is: Kane Williamson.
He asked Kane to answer some queries in a press interview.
Kane is irritated by Dhruv constant interruption during his interview,
so he decides to give Dhruv a run for his money by asking him the answer to various queries.
Williamson will give a query of the types mentioned below,
to the Dhruv and will expect him to answer those.
Push X -- Insert Williamson's score in an array. - Query type 1.
Diff -- Find out the difference between Willamson's current highest and current lowest score,
currently present in the array. And then remove a singular instance of those values from the array.
- Query type 2.
In case, the current lowest and current highest score are same,
then only one instance of that score will be removed from the array.
CountHigh -- Find out the number of times Williamson has scored his current highest score,
currently present in array. - Query type 3.
CountLow -- Find out the number of times Williamson has scored his current lowest score,
currently present in array. - Query type 4.

Input Format:
The first line contains an integer Q,
which denotes the number of queries which have to be dealt by Dhruv.
The next Q lines will contain a query like the ones mentioned above.

Constraints:
1 ≤ Q ≤ 10^5
1 ≤ X ≤ 10^5

Output Format:
For the query type 2, 3, and 4, print the answer in a new line.
If there is no record of any innings, that is,
the array of Williamson's score is empty for query type 2, 3 and 4, then print 1.

Sample Input:
10
CountHigh
Push 442
CountHigh
Push 7555
Diff
Push 2799
Diff
Push 8543
Diff
Diff
Sample Output:
-1
1
7113
0
988
-1
Time Limit: 1 sec
*/
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int main()
{
    int q;
    cin>>q;
    priority_queue<int> maxrun,minrun;
    int freq[100000]={0};
    int count=0;
    for(int i=0;i<q;i++)
    {
        char x[10];
        cin>>x;
        if(!strcmp(x,"Push"))
        {
            int n;
            cin>>n;
            freq[n]++;
            count++;
            minrun.push(-n);
            maxrun.push(n);
        }
        else if(!strcmp(x,"Diff"))
        {
            if(count<=0)
            {
                cout<<"-1"<<endl;
            }
            else
            {
                int high=maxrun.top();
                int low=-minrun.top();
                if(high!=low)
                {
                    freq[low]--;
                    count--;
                }
                freq[high]--;
                count--;
                maxrun.pop();
                minrun.pop();
                cout<<abs(high-low)<<endl;
            }
        }
        else if(!strcmp(x,"CountHigh"))
        {
            if(count<=0)
            {
                cout<<"-1"<<endl;
            }
            else
            {
                cout<<freq[maxrun.top()]<<endl;
            }
        }
        else if(!strcmp(x,"CountLow"))
        {
            if(count<=0)
            {
                cout<<"-1"<<endl;
            }
            else
            {
                cout<<freq[-minrun.top()]<<endl;
            }
        }
    }
	return 0;
}
