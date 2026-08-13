#include<bits/stdc++.h>
using namespace std;

string Removekdigit(string nums, int k){
    stack<int> st;
    int n = nums.size();
    for(int i=0;i<n;i++){
        int digit = nums[i];
        while (!st.empty() && k>0 && st.top() > digit)
        {
            st.pop();
            k--;
        }
        st.push(digit);
    }
    while(!st.empty() && k>0){
        st.pop();
        k--;
    }
    if(st.empty())  return "0";
    string res = "";
    while(!st.empty() ){
        res.push_back(st.top());
        st.pop();
    }

    reverse(res.begin() , res.end());

    return res;
}
int main(){
    string nums = "541892";
    int k = 2;
    string ans = Removekdigit(nums, k);
    cout << "The smallest possible integer after removing k digits is: " << ans;
    return 0;
}