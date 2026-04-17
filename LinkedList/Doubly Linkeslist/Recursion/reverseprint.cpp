#include <iostream>
using namespace std;

void reversePrint(int arr[], int index) {
    // Base case
    if (index < 0)
        return;

    // Print current element
    cout << arr[index] << " ";

    // Recursive call
    reversePrint(arr, index - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    reversePrint(arr, n - 1);

    return 0;
}
