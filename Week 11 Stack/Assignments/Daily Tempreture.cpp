#include <vector>   // Required for using the vector container
#include <stack>    // Required for using the stack container

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // Initialize the answer vector with 0s, the same size as the input temperatures vector
        vector<int> ans(temperatures.size(), 0);

        // Stack to store indices of the temperatures vector
        stack<int> st;

        // Loop through each temperature in the input vector
        for (int i = 0; i < temperatures.size(); i++) {
            
            // While the stack is not empty and the current temperature is greater than 
            // the temperature at the index stored at the top of the stack
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                
                // Calculate the number of days until a warmer temperature
                ans[st.top()] = i - st.top();

                // Remove the index from the stack
                st.pop();
            }

            // Push the current index onto the stack
            st.push(i);
        }

        // Return the resulting vector with the number of days until a warmer temperature
        return ans;
    }
};
