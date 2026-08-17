#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n);
    stack<int> st;
    
    for (int i = n - 1; i >= 0; i--) {
        while(!st.empty() && st.top()<= arr[i]){
            st.pop();
        }
        if(st.empty()){
            result[i] = -1;

        } else{
            result[i] = st.top();

        }
        st.push(arr[i]);

        
        // 2. agar stack khali hai, result[i] = -1, warna result[i] = stack.top()
        // 3. arr[i] ko push kar do
    }
    return result;
}


int main() {
    vector<int> arr = {};
    vector<int> result = nextGreaterElement(arr);
    
    for (int x : result) cout << x << " ";
    // Expected: 5 25 25 -1
    
    return 0;
}