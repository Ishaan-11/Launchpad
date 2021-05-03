/*#include<iostream>
using namespace std;
template<typename T>
struct node{
    string key;
    T value;
    node * next;

    node(string key,T value){
        this->key = key;
        this->value = value;
    }
    ~node(){
        if(next!=NULL){
            delete next;
        }
    }
};
template <typename T>
class hashtable{
    node<T> ** table;
    int ts;
    int cs;
    int hashFn(string key){
       int l = key.length();
       int p = 1;
       int ans = 0;
       for(int i=0;i<l;i++){
            ans+=key[i]*p;
            p = p*37;
            p = p%ts;
            ans = ans%ts;
       }
       return ans;
    }
    void rehash(){
        node <T> ** oldtable = table;
        int oldTs = ts;
        ts = 2*ts;
        cs = 0;
        table = new node<T> * [ts];
        for(int i=0;i<ts;i++){
            table[i] = NULL;
        }
        for(int i=0;i<oldTs;i++){
            node<T> * head = oldtable[i];
            while(head){
                insert(head->key,head->value);
                head = head->next;
            }
            delete oldtable[i];
        }
        delete [] oldtable;
    }
public:
    hashtable(int size=7){
        ts = size;
        cs = 0;
        table = new node<T> * [size];
        for(int i=0;i<ts;i++){
            table[i] = NULL;
        }
    }
    void insert(string key,T value){
        int index = hashFn(key);
        node<T> * temp = new node<T>(key,value);
        temp->next = table[index];
        table[index] = temp;
        cs++;
        float lf = (float)cs/ts;
        if(lf>0.7){
            rehash();
        }
    }
    T* find(string key){
        int index = hashFn(key);
        node<T> * head = table[index];
        while(head){
            if(head->key==key){
                return &(head->value);
            }
            head = head->next;
        }
        return NULL;
    }
    void erase(string key){
        int index = hashFn(key);
        node<T> * head = table[index];
        node<T> * parent = NULL;
        while(head){
            if(head->key==key){
                if(parent==NULL){
                    table[index] = head->next;
                    cs--;
                    //head->next = NULL;
                    delete head;
                    return;
                }
                parent->next = head->next;
                cs--;
                head->next = NULL;
                delete head;
                return;
            }
            parent = head;
            head = head->next;
        }
        return;
    }
    void print(){
        for(int i=0;i<ts;i++){
            node<T> * head = table[i];
            cout<<i<<"-->";
            while(head){
                cout<<head->key<<"-->";
                head = head->next;
            }
            cout<<"NULL"<<endl;
        }
    }
};
int main(){
hashtable<int> h;
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

}
*/
/*
#include<iostream>
#include<unordered_set>
using namespace std;
int main(){
int arr1[10] = {4,2, 8, 1, 6};
int arr2[10] = {4,9,2,5};
unordered_set<int> s;
for(int i=0;i<5;i++){
    s.insert(arr1[i]);
}
s.erase(2);
s.clear();
for(int i=0;i<4;i++){
    unordered_set<int>:: iterator it = s.find(arr2[i]);
    if(it==s.end()){
        cout<<arr2[i]<<" Does not exit"<<endl;
    }
    if(it!=s.end()){
        cout<<arr2[i]<<" exists"<<endl;;
    }
}
}
*/
/*
#include<iostream>
#include<map>
using namespace std;
map<int,vector<int> >m;
void insertInMap(node * root,int value){
    if(root==NULL){
        return;
    }

    m[value].push_back(root->data);
    insertInMap(root->left,value-1);
    insertInMap(root->right,value+1);
    return;
}
void print(){
    map<int,vector<int> >:: iterator it;
    for(it = m.begin();it!=m.end();it++){
        for(int i=0;i<it->second.size();i++){
            cout<< it->second[i];
        }
        cout<<endl;
    }
}
int main(){

}
*/
