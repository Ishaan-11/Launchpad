#include<iostream>
#include<climits>
using namespace std;
int main()
{
    int n,max=INT_MIN;
    char max_arr[100];
    cout<<"how many strings you want to enter? "<<endl;
    cin>>n;
    cin.get();
    for(int x=0;x<n;x++)
    {
        char a[100];
        cout<<"enter the "<<x+1<<" string: "<<endl;
        cin.getline(a,100);
        int i=0;
        while(a[i]!='\0')
        {
            i++;
        }
        if(i>max)
        {
            max=i;
            int j=0;
            while(j<=max)
            {
                max_arr[j]=a[j];
                j++;
            }
        }
    }
    cout<<"the largest string is: "<<max_arr;
    return 0;
}

