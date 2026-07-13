#include <bits/stdc++.h>
using namespace std;

    bool checkIthBit(int n, int i) {
        
        return (n & (1 << i)) != 0;  
    }


int main() {
    
    int num = 18;  // Binary: 101
    int bitIndex = 4;  // Check the 2nd bit (0-based index)

    if (checkIthBit(num, bitIndex)) {
        cout << "The " << bitIndex << " " << num << " is set (1)." << endl;
    } else {
        cout << "The " << bitIndex << "-th bit of " << num << " is not set (0)." << endl;
    }

    return 0;
}
