/*
Take as input a number N, print "Prime" if it is prime if not Print "Not Prime".


Constraints:
2 < N <= 1000000000
Sample Input:
3
Sample Output:
Prime
Explanation:
The output is case specific
*/
#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int i=2;
    while(i<n)
    {
        if(n%i==0)
        {
            cout<<"Not Prime";
            return 0;
        }
        i++;
    }
    cout<<"Prime";
    return 0;
}
