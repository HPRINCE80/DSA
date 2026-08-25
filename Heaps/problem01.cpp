#include<bits/stdc++.h>
using namespace std;
class MinHeap {
private:
    vector<int> heap;  // array-based storage
    
    // helper functions ke liye index nikalna
    int parent(int i);
    int leftChild(int i);
    int rightChild(int i);
    void heapifyUp(int i);

    
    
public:
    void insert(int val);
    int extractMin();
    int peek();
};


int MinHeap::parent(int i){
    return (i-1)/2;
}

int MinHeap::leftChild(int i){
    return (2*i) +1;
}

int MinHeap::rightChild(int i){
    return (2*i) +2;
}
void MinHeap::heapifyUp(int i){
    while(i > 0 && heap[i] < heap[parent(i)]){
        swap(heap[i],heap[parent(i)]);
        i = parent(i);
        // yahan i ko update karo
    }
}
void MinHeap::insert(int val){
    heap.push_back(val);
    heapifyUp(heap.size() - 1);
}
int MinHeap::peek(){
    return heap[0];

}
int main(){
    MinHeap h;
     h.insert(5);
    h.insert(3);
    h.insert(8);
    h.insert(1);
    cout<<"Min is "<<h.peek()<<endl;
    return 0;
}

