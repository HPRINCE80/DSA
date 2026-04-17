#include<bits/stdc++.h>
using namespace std;

int findmedian(vector<vector<int>>& matrix){
    int r = matrix.size();
    int c = matrix[0].size();

    int low = INT_MAX;
    int high = INT_MIN;

    for(int i=0;i<r;i++){
        low = min(low, matrix[i][0]);
        high = max(high,matrix[i][c-1]);
    }
    int desired = (r*c + 1) / 2;

    while(low< high){
        int mid = (low+high)/2;
        int count = 0;

        for(int i=0;i<r;i++){
            count +=  upper_bound(matrix[i].begin(),matrix[i].end(), mid) - matrix[i].begin();
        }

        if(count < desired)
            low = mid + 1;
        else
            high = mid;
    }

    return low;
    }

int main(){
    vector<vector<int>> matrix = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };
    cout << "Median: " <<findmedian(matrix) << endl;

    return 0;
}