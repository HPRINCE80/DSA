#include <bits/stdc++.h>
using namespace std;

    int largestRectangleArea(vector<int> &heights) {
        int n = heights.size();
        stack<int> st;

        int leftsmall[n], rightsmall[n];

        // Compute Nearest Smaller to Left (NSL) for each bar
        for (int i = 0; i < n; i++) {
            // Pop until a smaller element is found or stack is empty
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            // If stack is empty, no smaller element on the left
            leftsmall[i] = st.empty() ? 0 : st.top() + 1;

            // Push current index to stack
            st.push(i);
        }

        // Clear stack to reuse for NSR
        while (!st.empty()) st.pop();

        // Compute Nearest Smaller to Right (NSR) for each bar
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            // If stack is empty, no smaller to the right
            rightsmall[i] = st.empty() ? n - 1 : st.top() - 1;

            st.push(i);
        }

        // Calculate max area using NSL and NSR
        int maxA = 0;
        for (int i = 0; i < n; i++) {
            int width = rightsmall[i] - leftsmall[i] + 1;
            maxA = max(maxA, heights[i] * width);
        }

        return maxA;
    }

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3, 1};
    

    // Output the largest area
    cout << "The largest area in the histogram is " << largestRectangleArea(heights) << endl;
    return 0;
}
