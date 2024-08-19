#include <stack>   // Required for using the stack container
#include <string>  // Required for using the string class

class Solution {
public:
    int minAddToMakeValid(std::string s) {
     stack<char> st; // Stack to keep track of open parentheses
        int ans = 0; // Counter for minimum additions required

        // Iterate through each character in the string
        for (auto ch : s) {
            if (ch == '(') {
                ans++; // Increase the counter for an unmatched '('
                st.push(ch); // Push the open parenthesis onto the stack
            } else {
                if (!st.empty()) {
                    --ans; // Decrease the counter for a matching ')'
                    st.pop(); // Pop the matching '(' from the stack
                } else {
                    ans++; // Increment the counter for an unmatched ')'
                }
            }
        }

        // The counter 'ans' now holds the minimum number of additions required
        return ans;
    }
};
