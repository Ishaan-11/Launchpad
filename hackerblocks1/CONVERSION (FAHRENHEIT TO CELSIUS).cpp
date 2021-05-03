/*

Take the following as input.

Minimum Fahrenheit value
Maximum Fahrenheit value
Step

Print as output the Celsius conversions. Use the formula C = (5/9)(F – 32)
E.g. for an input of 0, 100 and 20 the output is
0 17
20 6
40 4
60 15
80 26
100 37


Constraints:
0 < Min < 100
Min < Max < 500
0 < Step
Sample Input:
0
100
20
Sample Output:
0 -17
20 -6
40 4
60 15
80 26
100 37
Explanation:
First number in every output line is fahrenheit, second number is celsius.
The two numbers are separated by a tab.
*/
#include <iostream>
using namespace std;
int main()
{
    int start,end,step,c;
    cin>>start;
    cin>>end;
    cin>>step;
    for(int i=start;i<=end;i+=step)
    {
        c=(5*(i-32))/9;
        cout<<i<<"\t"<<c<<endl;
    }
    return 0;
}
