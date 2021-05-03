#include <iostream>
#include<unordered_map>
#define hashmap unordered_map<char,node*>
using namespace std;
struct node
{
    char data;
    hashmap h;
    bool isTerminal;
    node(char d)
    {
        data=d;
        isTerminal=false;
    }
};
class trie
{
    node *root;
    public:
    trie()
    {
        root=new node('\0');
    }
    //insertion
    void addword(char *word)
    {
        node*temp=root;
        for(int i=0;word[i]!='\0';i++)
        {
            char ch=word[i];
            if(temp->h.count(ch)==0)
            {
                node* child=new node(ch);
                temp->h[ch]=child;
                temp=child;
            }
            else
            {
                temp=temp->h[ch];
            }
        }
        temp->isTerminal=true;
        return;
    }
    bool search(char *word)
    {
        node* temp=root;
        for(int i=0;word[i]!='\0';i++)
        {
            char ch=word[i];
            if(temp->h.count(ch))
            {
                temp=temp->h[ch];
            }
            else
            {
                return false;
            }
        }
        return temp->isTerminal;
    }
};
int main()
{
    char word[10][100]={"apple","ape","coder","coding blocks","no"};
    trie t;
    for(int i=0;i<5;i++)
    {
        t.addword(word[i]);
    }
    char searchword[100];
    cin.getline(searchword,100);
    if(t.search(searchword))
    {
        cout<<searchword<<" found"<<endl;
    }
    else
    {
        cout<<"not found"<<endl;
    }
    return 0;
}
