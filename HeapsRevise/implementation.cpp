#include <bits/stdc++.h>
using namespace std;

class MaxHeap
{
    vector<int> Heap;

public:

    // INSERTION
    void insert(int val)
    {
        Heap.push_back(val);

        int i = Heap.size() - 1;

        while (i > 0)
        {
            int parent = (i - 1) / 2;

            if (Heap[parent] >= Heap[i])
                break;

            swap(Heap[parent], Heap[i]);

            i = parent;
        }
    }

    // DELETION
    void deleteRoot()
    {
        // Heap empty
        if (Heap.empty()) return;

        // Last element ko root par lao
        Heap[0] = Heap.back();

        // Last element remove
        Heap.pop_back();

        int i = 0;

        // Heapify Down
        while (true)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            int largest = i;

            // Left child
            if (left < Heap.size() &&
                Heap[left] > Heap[largest])
            {
                largest = left;
            }

            // Right child
            if (right < Heap.size() &&
                Heap[right] > Heap[largest])
            {
                largest = right;
            }

            // Already correct position
            if (largest == i)
                break;

            swap(Heap[i], Heap[largest]);

            i = largest;
        }
    }

    // PRINT
    void print()
    {
        for (int x : Heap)
        {
            cout << x << " ";
        }

        cout << endl;
    }
};

int main()
{
    MaxHeap H;

    H.insert(50);
    H.insert(40);
    H.insert(30);
    H.insert(20);
    H.insert(10);

    H.print();

    H.deleteRoot();
    H.deleteRoot();

    H.print();

    return 0;
}