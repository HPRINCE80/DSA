#include <bits/stdc++.h>
using namespace std;

    // Function to find the union of two arrays using set
    vector<int> findUnion(int arr1[], int arr2[], int n, int m) {
        // Create a set to store unique elements
        set<int> st;

        // Insert elements from first array
        for (int i = 0; i < n; i++) {
            st.insert(arr1[i]);
        }

        // Insert elements from second array
        for (int i = 0; i < m; i++) {
            st.insert(arr2[i]);
        }

        // Convert set to vector
        vector<int> unionArr(st.begin(), st.end());
        return unionArr;
    }


int main() {
    int n = 10, m = 7;
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[] = {2, 3, 4, 4, 5, 11, 12};

    
    vector<int> result = findUnion(arr1, arr2, n, m);

    cout << "Union of arr1 and arr2 is: ";
    for (int val : result) {
        cout << val << " ";
    }
   

}
