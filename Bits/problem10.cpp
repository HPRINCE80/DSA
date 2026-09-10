#include <bits/stdc++.h>
using namespace std;


    /* Function to find the XOR 
    of numbers from 1 to n*/
    int XORtillN(int n) {
        if(n % 4 == 1) return 1;
        if(n % 4 == 2) return n+1;
        if(n % 4 == 3) return 0;
        return n;
    }
    /* Function to find the XOR 
    of numbers from L to R*/
    int findRangeXOR(int l, int r){			
		return XORtillN(l-1) ^ XORtillN(r);
	}


int main() {
    int l = 1, r = 3;
    
    /* Creating an instance of 
    Solution class */
    
    
    /* Function call to get the
    XOR of numbers from L to R*/
    int ans = findRangeXOR(l, r);
    
    cout << "The XOR of numbers from " << l << " to " << r << " is: " << ans;
    
    return 0;
}
