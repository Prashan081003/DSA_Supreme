#include <string>  // Required for using the string class
#include <stack>   // Required for using the stack container
#include <algorithm> // Required for using the max function

using namespace std;

class Solution {
public:
    // Function to find the length of the longest valid (well-formed) parentheses substring
    int longestValidParentheses(string s) {
        stack<int> st; // Stack to store indices of the string
        st.push(-1);   // Initialize the stack with -1 to handle edge cases
        int maxLen = 0; // Variable to keep track of the maximum length of valid parentheses

        // Iterate through each character in the string
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i]; // Current character

            // If the character is an opening bracket '('
            if (ch == '(') {
                st.push(i); // Push the index onto the stack
            } 
            else { // If the character is a closing bracket ')'
                st.pop(); // Pop the top element from the stack

                // If the stack is empty after popping, push the current index
                if (st.empty()) {
                    st.push(i);
                } 
                else {
                    // Calculate the length of the current valid parentheses substring
                    int length = i - st.top();
                    // Update maxLen if the current length is greater
                    maxLen = max(length, maxLen);
                }
            }
        }
        return maxLen; // Return the maximum length of valid parentheses
    }
};
