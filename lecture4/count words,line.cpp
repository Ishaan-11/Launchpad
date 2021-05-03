#include<iostream>
using namespace std;
int main()
{
    int word=0,line=0,word_length=0;
    char a;
    a=cin.get();
    while(a!='$')
    {
        if(a==' '||a=='\t')
        {
            if(word_length>0)
            {
                word++;
                word_length=0;

            }
        }
        else if(a=='\n')
        {
            line++;
            if(word_length>0)
            {
                word++;
                word_length=0;

            }
        }
        else
        {
            word_length++;
        }
        a=cin.get();
    }
    if(word_length>0)
    {
        word++;
    }
    cout<<"words: "<<word<<endl;
    cout<<"line: "<<line+1<<endl;
    return 0;
}
