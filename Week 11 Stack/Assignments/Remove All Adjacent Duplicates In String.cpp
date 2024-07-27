#include <string>
#include <stack>
#include <algorithm> // For reverse function
using namespace std;

class Solution {
public:
    /**
     * Function to remove all adjacent duplicates in the given string.
     * @param s: A string from which adjacent duplicates are to be removed.
     * @return A string with all adjacent duplicates removed.
     */
    string removeDuplicates(string s) {
        stack<char> st; // Stack to keep track of characters

        // Iterate through each character in the input string
        for (auto ch : s) {
            // If the stack is not empty and the top of the stack is the same as the current character, pop the stack
            if (!st.empty() && st.top() == ch) {
                st.pop();
            } else {
                // Otherwise, push the current character onto the stack
                st.push(ch);
            }
        }

        // Prepare the result string from the stack
        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        // Reverse the result string to maintain the original order
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
