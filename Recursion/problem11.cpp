#include<bits/stdc++.h>
using namespace std;
void solve(int index, int k, int target,int current_sum, vector<int> current, vector<vector<int>>& result){
   if(current.size() == k && current_sum == target){
    result.push_back(current);
    return;
}
   if(index > 9) return;
solve(index+1, k, target, current_sum, current, result);

// include
current.push_back(index);
solve(index+1, k, target, current_sum + index, current, result);
current.pop_back();


}
int main(){
    int k =3;
    int target =7;
    vector<vector<int>> result;
    solve(1,k,target,0,{},result);

    for(vector<int>subset: result){
        cout<<"[";
        for(int x : subset){
cout<<x;
        }
        cout<<"]";
        cout<<",";
    }

    return 0;
}