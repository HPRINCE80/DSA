#include<bits/stdc++.h>
using namespace std;

    vector<vector<int>> primeFactorize(vector<int>& queries) {
        vector<vector<int>> result;
        
        for (int i = 0; i < queries.size(); i++) {
            int n = queries[i];
            vector<int> temp;
            
            int divisor = 2;
            while (divisor * divisor <= n) {
                if (n % divisor == 0) {
                    temp.push_back(divisor);
                    n = n / divisor;
                } else {
                    divisor++;
                }
            }
            
            if (n > 1) {
                temp.push_back(n);
            }
            
            result.push_back(temp);
        }
        
        return result;
    }

int main(){

    vector<int>  queries = {2, 3, 4, 5, 6};
    vector<vector<int>> ans =  primeFactorize(queries);
    for(vector<int> subset : ans){
        cout<<"{";
        for(int x : subset){

            cout<<x<<" ";
        }
        cout<<"},";
    }

    return 0;
}
