/*
It's winter season.
There is a long queue of students from the four prime courses at Coding Blocks and
everyone is here to grab his hoodie.
Each student of a course has a different roll number.
Whenever a new student will come, he will search for his friend from the end of the queue.
Note that a student can only has friend from his course and not from any other course.
As soon as he will find any of the friend in the queue,
he will stand behind him, otherwise he will stand at the end of the queue.
At any moment Prateek Bhaiya will ask the student,
who is standing in front of the queue,
to come and put his name and grab his hoodie and then remove that student from the queue.
There are Q operations of one of the following types:

E x y : A new student of course x whose roll number is y will stand in queue
according to the method mentioned above.

D : Prateek Bhaiya will ask the student, who is standing in front of the queue,
to come and put his name for the hoodie and remove him from the queue.

Find out the order in which student put their name.

Note: Number of dequeue operations will never be greater than enqueue operations at any point of time.

Input Format:
First line contains an integer Q, denoting the number of operations.
Next Q lines will contains one of the 2 types of operations.

Constraints:
1 ≤ x ≤ 4
1 ≤ y ≤ 50000
1 ≤ Q ≤ 100000
Output Format:
For each 2nd type of operation, print two space separated integers,
the front student's course and roll number.

Sample Input:
5
E 1 1
E 2 1
E 1 2
D
D
Sample Output:
1 1
1 2
*/
#include<iostream>
#include<stack>
#include<queue>
#include<climits>
using namespace std;
void insert(queue<int> c[5],int x,int y)
{
    switch(x)
    {
        case 1: c[1].push(y);
                break;
        case 2: c[2].push(y);
                break;
        case 3: c[3].push(y);
                break;
        case 4: c[4].push(y);
                break;
    }
    return;
}
int min(int a[5])
{
    int m=INT_MAX;
    int j=0;
    for(int i=1;i<5;i++)
    {
        if(a[i]<m && a[i]!=0)
        {
            m=a[i];
            j=i;
        }
    }
    return j;
}
int main()
{
    stack<char> s;
    queue<int> c[5];
    int a[5]={0};
    int q;
    cin>>q;
    for(int i=1;i<=q;i++)
    {
        char o;
        cin>>o;
        s.push(o);
        if(o=='E')
        {
            int x,y;
            cin>>x;
            cin>>y;
            if(a[x]==0)
            {
                a[x]=i;
            }
            insert(c,x,y);
        }
        else
        {
            int m=min(a);
            while(!s.empty())
            {
                char top=s.top();
                s.pop();
                if(top=='D')
                {
                    cout<<m<<" "<<c[m].front()<<endl;;
                    c[m].pop();
                }
                if(c[m].empty())
                {
                a[m]=0;
                m=min(a);
                }
            }
        }
    }
	return 0;
}
//better method
/*
#include<iostream>
#include<queue>
using namespace std;
int main()
{
    queue<int> q[5];
    queue<int> sequence;
    int n,course,roll;
    cin>>n;
    char Q;
    for(int i=0;i<n;i++)
    {
        cin>>Q;
        if(Q=='E')
        {
            cin>>course>>roll;
            if(q[course].empty())
            {
                sequence.push(course);
            }
            q[course].push(roll);
        }
        else if(Q=='D')
        {
            int first=sequence.front();
            cout<<first<<" "<<q[first].front()<<endl;
            q[first].pop();
            if(q[first].empty())
            {
                sequence.pop();
            }
        }
    }
	return 0;
}
*/
