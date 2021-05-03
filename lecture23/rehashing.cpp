#include<iostream>
using namespace std;
template<typename T>
struct node
{
    string key;
    T value;
    node* next;
    node(string key,T value)
    {
        this->key=key;
        this->value=value;
    }
    ~node()
    {
        if(next!=NULL)
        {
            delete next;
        }
    }
};
template<typename T>
class hashtable
{
    int ts;
    int cs;
    node<T>**table;
    int hashfn(string key)
    {
        int l=key.length();
        int p=1;
        int ans=0;
        for(int i=0;i<l;i++)
        {
            ans=ans+key[i]*p;
            p=p*37;
            p=p%ts;
            ans=ans%ts;
        }
        return ans;
    }
    void rehash()
    {
        node<T>**oldtable=table;
        int oldts=ts;
        ts=2*ts;
        cs=0;
        table=new node<T>*[ts];
        for(int i=0;i<ts;i++)
        {
            table[i]=NULL;
        }
        for(int i=0;i<oldts;i++)
        {
            node<T>*head=oldtable[i];
            while(head)
            {
                insert(head->key,head->value);
                head=head->next;
            }
            delete oldtable[i];
        }
        delete []oldtable;
    }
public:
    hashtable(int size)
    {
        ts=size;
        cs=0;
        table=new node<T>*[size];
        for(int i=0;i<ts;i++)
        {
            table[i]=NULL;
        }
    }
    void insert(string key,T value)
    {
        int index=hashfn(key);
        node<T>*temp=new node<T>(key,value);
        temp->next=table[index];
        table[index]=temp;
        float lf=(float)cs/ts;
        if(lf>0.7)
        {
            rehash();
        }
        cs++;
        return;
    }
    T *find(string key)
    {
        int index=hashfn(key);
        node<T>*head=table[index];
        while(head)
        {
            if(head->key==key)
            {
                return &(head->value);
            }
            head=head->next;
        }
        return NULL;
    }
    void erase(string key)
    {
        int index=hashfn(key);
        node<T>*head=table[index];
        node<T>*parent=NULL;
        while(head)
        {
            if(head->key==key)
            {
                if(parent==NULL)
                {
                    table[index]=head->next;
                    head->next=NULL;
                    delete head;
                    cs--;
                    return;
                }
                parent->next=head->next;
                head->next=NULL;
                delete head;
                cs--;
            }
            parent=head;
            head=head->next;
        }
        return;
    }
    void print()
    {
        for(int i=0;i<ts;i++)
        {
            node<T> * head = table[i];
            cout<<i<<"-->";
            while(head)
            {
                cout<<head->key<<"-->";
                head = head->next;
            }
            cout<<"NULL"<<endl;
        }
        return;
    }
};
int main()
{
    hashtable<int> h(7);
    /*h.insert("abc",1);
    h.insert("wefwe",1);
    h.insert("dsvd",1);
    cout<<"*************************"<<endl;
    h.print();
    h.insert("asn",1);
    h.insert("efe",1);
    h.insert("vdd",1);
    h.insert("eeq",1);
    h.print();
    cout<<"*************************"<<endl;
    h.erase("dsvd");
    h.print();*/
h.insert("abc",1);
h.insert("wefwe",1);
h.insert("dsvd",1);
h.insert("asn",1);
h.print();
cout<<endl;
h.insert("efe",1);
h.insert("vdd",1);
h.insert("eeq",1);
h.print();
cout<<endl;
h.erase("eeq");
h.print();
    return 0;
}
