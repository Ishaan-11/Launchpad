/*node * removeElement(node * root,int element){
    if(root==NULL){
        return NULL;
    }
    if(root->data==element){
        // 0 child
        if(!root->left && !root->right){
            delete root;
            return NULL;
        }

        //1 child
        if(!root->left && root->right){
            node * it = root;
            delete root;
            return it->right;
        }
        if(root->left && !root->right){
            node * it = root;
            delete root;
            return it->left;
        }

        //2 child
        node * parent = root;
        node * it = root->right;
        if(it->left==NULL){
            it->left = root->left;
            delete root;
            return it;
        }
        while(it->left!=NULL){
            parent = it;
            it = it->left;
        }
        parent->left = it->right;
        it->left = root->left;

        if(root->right!=it){
            it->right = root->right;
        }
        delete root;
        return it;
    }

    if(root->data < element){
        root->right = removeElement(root->right,element);
    }else{
        root->left = removeElement(root->left,element);
    }
    return root;
}*/
#include<iostream>
#include<vector>
using namespace std;
class Heap{
    vector<int>v;
    void heapify(int i){
        int minIndex = i;
        int left = 2*i;
        int right = 2*i +1;
        if(left<v.size() && v[minIndex] > v[left]){
            minIndex = left;
        }
        if(right<v.size() && v[minIndex] > v[right]){
            minIndex = right;
        }
        if(minIndex!=i){
            swap(v[i],v[minIndex]);
            heapify(minIndex);
        }
    }
public:
    Heap(){
        v.push_back(-1);
    }

    void addElement(int data){
        v.push_back(data);
        int index = v.size()-1;
        while(index>1 && v[index/2]>v[index]){
            swap(v[index/2],v[index]);
            index = index/2;
        }
    }

    bool isEmpty(){
        return v.size()==1;
    }

    int min(){
        if(isEmpty()){
            return -1;
        }
        return v[1];
    }


    int removeMin(){
        int top = v[1];
        v[1] = v[v.size()-1];
        v.pop_back();
        heapify(1);
        return top;
    }
    void print(){
        for(int i=1;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
Heap p;
p.addElement(4);p.addElement(1);p.addElement(5);
p.addElement(7);p.addElement(2);p.addElement(3);
p.print();
cout<<p.removeMin();
p.print();
cout<<p.removeMin();
p.print();
}

#include<iostream>
#include<vector>
using namespace std;
void heapify(int arr[10],int i,int n){
    int left = 2*i;
    int right = 2*i+1;
    int minIndex = i;
    if(left<n && arr[minIndex]>arr[left]){
        minIndex = left;
    }
    if(right<n && arr[minIndex]>arr[right]){
        minIndex = right;
    }
    if(i!=minIndex){
        swap(arr[i],arr[minIndex]);
        heapify(arr,minIndex,n);
    }
}
void heapSort(int arr[10],int n){
    //construct tree
    for(int i=n/2;i>0;i--){
        heapify(arr,i,n);
    }
    //extract min
    //place at last
    //heapify
    for(int i=n-1;i>0;i--){
        swap(arr[i],arr[1]);
        heapify(arr,1,i);
    }
}
int main(){
int arr[10] = {-1,5,8,2,4,1};
heapSort(arr,6);
for(int i=1;i<6;i++){
    cout<<arr[i]<<" ";
}
}
