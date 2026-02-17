#include <bits/stdc++.h>
using namespace std;

// first occurrence
int firstOcc(int n, int key, vector<int>& v) {
    int start = 0, end = n - 1;
    int res = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (v[mid] == key) {
            res = mid;
            end = mid - 1; // left side search
        }
        else if (key < v[mid]) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    return res;
}

// last occurrence
int lastOcc(int n, int key, vector<int>& v) {
    int start = 0, end = n - 1;
    int res = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (v[mid] == key) {
            res = mid;
            start = mid + 1; // right side search
        }
        else if (key < v[mid]) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    return res;
}

// count function
int countTarget(int n, int key, vector<int>& v) {
    int first = firstOcc(n, key, v);

    if (first == -1)
        return 0;

    int last = lastOcc(n, key, v);

    return last - first + 1;
}

int main() {
    int n = 7;
    int key = 13;
    vector<int> v = {3, 4, 13, 13, 13, 20, 40};

    cout << "Count of target = " << countTarget(n, key, v);

    return 0;
}