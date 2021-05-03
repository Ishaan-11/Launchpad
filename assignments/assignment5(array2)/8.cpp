#include<iostream>
using namespace std;
int main()
{
    char a[100];
    int c=0;
    cout<<"enter a string"<<endl;
    cin.getline(a,100);
    for(int i=0;a[i]!='\0';i++)
    {
        for(int j=i;a[j]!='\0';j++)
        {
            int x=0;
            for(int k=i;k<=j;k++)
            {
                int start=k,end=j;
                while(start<end)
                {
                    if(a[start]!=a[end])
                    {
                        x=1;
                        break;
                    }
                    start++;
                    end--;
                }
                if(x==0)
                {
                    c++;
                }
            }
        }
    }
    cout<<"number of substring which are palindrome are: "<<c;
    return 0;
}
