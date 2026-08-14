#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the index of celebrity
    int celebrity(vector<vector<int>> &M){
        
        // Size of given matrix
        int n = M.size();
        
        /* To store count of people who 
        know person of index i */
        vector<int> knowMe(n, 0);
        
        /* To store count of people who 
        the person of index i knows */
        vector<int> Iknow(n, 0);
        
        // Traverse on given matrix
        for(int i=0; i < n; i++) {
            for(int j=0; j < n; j++) {
                
                // If person i knows person j
                if(M[i][j] == 1) {
                    knowMe[j]++;
                    Iknow[i]++;
                }
            }
        }
        
        // Traverse for all persons to find the celebrity
        for(int i=0; i < n; i++) {
            
            // Return the index of celebrity
            if(knowMe[i] == n-1 && Iknow[i] == 0) {
                return i;  
            }
        }
        
        // Return -1 if no celebrity is found
        return -1;
    }
};

int main() {
    vector<vector<int>> M = {
        {0,1},{1,0}
        //  {0, 1, 1, 0}, 
        //  {0, 0, 0, 0}, 
        //  {1, 1, 0, 0}, 
        //  {0, 1, 1, 0}
    };
    
    /* Creating an instance of 
    Solution class */
    Solution sol; 
    
    // Function call to find the index of celebrity
    int ans = sol.celebrity(M);
    
    cout << "The index of celebrity is: " << ans;
    
    return 0;
}