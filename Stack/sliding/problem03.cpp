// #include <bits/stdc++.h>
// using namespace std;

//     // Function to find the index of celebrity
//     int celebrity(vector<vector<int>> &M){
        
//         // Size of given matrix
//         int n = M.size();
        
//         /* To store count of people who 
//         know person of index i */
//         vector<int> knowMe(n, 0);
        
//         /* To store count of people who 
//         the person of index i knows */
//         vector<int> Iknow(n, 0);
        
//         // Traverse on given matrix
//         for(int i=0; i < n; i++) {
//             for(int j=0; j < n; j++) {
                
//                 // If person i knows person j
//                 if(M[i][j] == 1) {
//                     knowMe[j]++;
//                     Iknow[i]++;
//                 }
//             }
//         }
        
//         // Traverse for all persons to find the celebrity
//         for(int i=0; i < n; i++) {
            
//             // Return the index of celebrity
//             if(knowMe[i] == n-1 && Iknow[i] == 0) {
//                 return i;  
//             }
//         }
        
//         // Return -1 if no celebrity is found
//         return -1;
//     }

// int celebrityoptimals(vector<vrctor<int> & M){

// }

// int main() {
//     vector<vector<int>> M = {
//         {0,1},{1,0}
//         //  {0, 1, 1, 0}, 
//         //  {0, 0, 0, 0}, 
//         //  {1, 1, 0, 0}, 
//         //  {0, 1, 1, 0}
//     };
    
//     /* Creating an instance of 
//     Solution class */
//     Solution sol; 
    
//     // Function call to find the index of celebrity
//     int ans = sol.celebrity(M);
    
//     cout << "The index of celebrity is: " << ans;
    
//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the index of celebrity
    int celebrity(vector<vector<int>> &M){
        
        // Size of given matrix
        int n = M.size();
        
        // Top and Down pointers
        int top = 0, down = n-1;
        
        // Traverse for all the people
        while(top < down) {
            
            /* If top knows down, 
            it can not be a celebrity */
            if(M[top][down] == 1) {
                top = top + 1;
            }
            
            /* If down knowns top, 
            it can not be a celebrity */
            else if(M[down][top] == 1) {
                down = down - 1;
            }
            
            /* If both does not know each other, 
            both cannot be the celebrity */
            else {
                top++;
                down--;
            }
        }
        
        // Return -1 if no celebrity is found
        // if(top > down) return -1;
        
        /* Check if the person pointed 
        by top is celebrity */
        for(int i=0; i < n; i++) {
            if(i == top) continue;
            
            // Check if it is not a celebrity
            if(M[top][i] == 1 || M[i][top] == 0) {
                return -1;
            }
        }
        
        // Return the index of celebrity
        return top;
    }
};

int main() {
    vector<vector<int>> M = {
         {0, 1, 1}, 
         {0, 0, 1}, 
         {0, 0, 0}
    };
    
    /* Creating an instance of 
    Solution class */
    Solution sol; 
    
    // Function call to find the index of celebrity
    int ans = sol.celebrity(M);
    
    cout << "The index of celebrity is: " << ans;
    
    return 0;
}