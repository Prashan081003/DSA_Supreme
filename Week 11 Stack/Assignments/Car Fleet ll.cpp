#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        vector<double> ans(cars.size(), -1); // Initialize the answer vector with -1
        stack<int> st; // Stack to keep track of the indices of cars
        
        for (int i = cars.size() - 1; i >= 0; --i) {
            // Pop cars from the stack that are slower or have the same speed
            while (!st.empty() && cars[st.top()][1] >= cars[i][1]) {
                st.pop();
            }

            // Calculate collision time with the next car in the stack
            while (!st.empty()) {
                double colTime = (double)(cars[st.top()][0] - cars[i][0]) / (cars[i][1] - cars[st.top()][1]);

                // Check if the calculated collision time is valid
                if (ans[st.top()] == -1 || colTime <= ans[st.top()]) {
                    ans[i] = colTime;
                    break;
                }
                st.pop(); // Pop if no valid collision time is found
            }

            st.push(i); // Push the current car's index onto the stack
        }

        return ans; // Return the calculated collision times
    }
};
