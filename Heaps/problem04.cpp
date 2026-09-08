#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    // Min Heap banaya
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    minHeap.push(5);
    minHeap.push(1);
    minHeap.push(8);
    minHeap.push(3);
    minHeap.push(9);

    cout << "Min Heap top (smallest): " << minHeap.top() << endl;

    // Max Heap banaya (empty)
    priority_queue<int> maxHeap;

    // Min heap se elements nikal ke max heap mein daalo
    while (!minHeap.empty()) {
        maxHeap.push(minHeap.top());
        minHeap.pop();
    }

    cout << "Max Heap top (largest): " << maxHeap.top() << endl;

    // Max heap ke saare elements print karo (descending order mein niklenge)
    cout << "Max Heap elements: ";
    while (!maxHeap.empty()) {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    cout << endl;

    return 0;
}