
#include <bits/stdc++.h>
using namespace std;


    // Function to calculate least number of units of time to finish all tasks with cooldown
    int leastInterval(vector<char>& tasks, int n) {

        // Step 1: Count frequency of each task
        unordered_map<char, int> freq;
        for (char task : tasks) {
            freq[task]++;
        }

        // Step 2: Use max heap to always pick task with highest frequency
        priority_queue<int> maxHeap;
        for (auto& entry : freq) {
            maxHeap.push(entry.second);
        }

        // Total time required
        int time = 0;

        // Step 3: Process tasks in cycles of size (n + 1)
        while (!maxHeap.empty()) {

            // Store tasks executed in this cycle
            vector<int> temp;

            // Set number of tasks allowed in this cycle
            int cycle = n + 1;

            // Counter to track how many tasks we run in this cycle
            int i = 0;

            // Keep running tasks until cycle ends or heap gets empty
            while (i < cycle && !maxHeap.empty()) {

                // Get the most frequent remaining task
                int cnt = maxHeap.top();
                maxHeap.pop();

                // Reduce its count as we’re running it once
                cnt--;

                // If the task still has pending frequency, store it for later
                if (cnt > 0) {
                    temp.push_back(cnt);
                }

                // Count 1 unit of time for this task
                time++;

                // Move to next slot in the cycle
                i++;
            }

            // Step 4: Push leftover tasks of this cycle back into the heap
            for (int val : temp) {
                maxHeap.push(val);
            }

            // Step 5: If heap is empty, no need to count idle time
            if (maxHeap.empty()) break;

            // Step 6: Add idle time to complete the cycle (if any slots were left)
            time += (cycle - i);
        }

        // Return the total time needed
        return time;
    }


// Driver code
int main() {
    

    // Input task list
    vector<char> tasks = {'A','A','A','B','B','B'};

    // Cooldown period
    int n = 2;

    // Output the least interval required to finish all tasks
    cout << leastInterval(tasks, n) << endl;

    return 0;
}
