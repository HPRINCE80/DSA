#include<bits/stdc++.h>
using namespace std;
int trap(vector<int>& height){
    int n = height.size();

    int left = 0;
    int right = n-1;

    int maxleft = 0;
    int maxRight = 0;

    int totalwater = 0;

    while(left< right){
        if(height[left]<= height[right]){
            if(height[left]>= maxleft){
                maxleft = height[left];

            }else{
                totalwater += maxleft - height[left];

            }
            left++;
        }
        else{
            if(height[right]>= maxRight){
                maxRight = height[right];

            }else{
                totalwater += maxRight - height[right];

            }
            right--;
        }
    }
    return totalwater;

}
int main(){
        vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
        int result = trap(height);
          cout << "Trapped Rainwater: " << result << endl;
    return 0;
}