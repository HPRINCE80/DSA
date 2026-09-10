#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    /* Function to find the indices of previous 
    greater element for each element in the array */
    vector<int> findPGE(vector<int> arr) {
        
        int n = arr.size(); //size of array
        
        // To store the previous greater elements
        vector<int> ans(n);
        
        // Stack to get elements in LIFO fashion
        stack<int> st;
        
        // Start traversing from the front
        for(int i=0; i < n; i++) {
            
            // Get the current element
            int currEle = arr[i];
            
            /* Pop the elements in the stack until 
            the stack is not empty and the top 
            element is not the greater element */
            while(!st.empty() && arr[st.top()] <= currEle) {
                st.pop();
            }
            
            /* If the greater element is not 
            found, stack will be empty */
            if(st.empty()) 
                ans[i] = -1;
                
            // Else store the answer
            else 
                ans[i] = st.top();
            
            // Push the current index in the stack 
            st.push(i);
        }
        
        // Return the result
        return ans;
    }
    
public:
    // Function to find the span of stock prices for each day
    vector <int> stockSpan(vector<int> arr, int n) {
        
        // Get the indices of previous greater elements
        vector<int> PGE = findPGE(arr);
        
        
        // To store the answer
        vector<int> ans(n);
        
        // Compute the result
        for(int i=0; i < n; i++) {
            ans[i] = i - PGE[i];
        }
        
        // Return the result
        return ans;
    }
};

int main() {
    int n = 7;
    vector<int> arr = {120, 100, 60, 80, 90, 110, 115};
    
    /* Creating an instance of 
    Solution class */
    Solution sol; 
    
    /* Function call to find the span 
    of stock prices for each day */
    vector<int> ans = sol.stockSpan(arr, n);
    
    cout << "The span of stock prices is: ";
    for(int i=0; i < n; i++) {
        cout << ans[i] << " ";
    }
    
    return 0;
}