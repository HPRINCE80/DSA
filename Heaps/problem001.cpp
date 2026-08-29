#include<bits/stdc++.h>
using namespace std;
class Maxheap{

    int * arr;
    int size;
    int total_size;

    public:

    Maxheap(int n){
        arr = new int [n];
        size = 0;
        total_size = n;
    }

    void insert(int value){
        if(size==total_size){
            cout<<"Heap Overflow";
            return;
        }
        arr[size]= value;
        int index = size;
        size++;

        while (index>0 && arr[(index-1)/2]<arr[index])
        {

            swap(arr[index],arr[(index-1)/2]);
            index = (index-1)/2;
            /* code */
        } 
        cout<<arr[index]<<" is inserted into the heap\n";
        
    }

    void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";

            cout<<endl;
        }
    }
    


};

int main() {
    Maxheap H1(6);
    H1.insert(4);
    H1.insert(14);
    H1.insert(11);
    H1.print();

    return 0;
}