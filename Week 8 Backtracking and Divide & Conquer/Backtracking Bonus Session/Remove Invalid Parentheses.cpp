#include <string>           // Required for using the string class
#include <unordered_set>    // Required for using the unordered_set data structure
#include <vector>           // Required for using the vector data structure

using namespace std;

class Solution {
public:
    // Recursive function to solve the problem of removing invalid parentheses
    // s: input string containing parentheses and other characters
    // ans: unordered set to store unique valid strings
    // open: number of open parentheses that need to be removed
    // close: number of close parentheses that need to be removed
    // bal: balance of open and close parentheses
    // index: current index in the input string
    // output: current valid output string being formed
    void solve(string &s, unordered_set<string>& ans, int open, int close, int bal, int index, string &output) {
        // Base case: if we've reached the end of the string
        if (index >= s.length()) {
            // If open, close, and balance are all zero, we have a valid answer
            if (open == 0 && close == 0 && bal == 0) {
                ans.insert(output);
            }
            return;
        }

        // If the current character is not a parenthesis, add it to the output
        if (s[index] != '(' && s[index] != ')') {
            output.push_back(s[index]);
            solve(s, ans, open, close, bal, index + 1, output);
            output.pop_back();
        } else {
            // Handling parentheses
            if (s[index] == '(') {
                // Option 1: Exclude the open parenthesis
                if (open > 0) {
                    solve(s, ans, open - 1, close, bal, index + 1, output);
                }
                // Option 2: Include the open parenthesis
                output.push_back('(');
                solve(s, ans, open, close, bal + 1, index + 1, output);
                output.pop_back();
            } else if (s[index] == ')') {
                // Option 1: Exclude the close parenthesis
                if (close > 0) {
                    solve(s, ans, open, close - 1, bal, index + 1, output);
                }
                // Option 2: Include the close parenthesis if balance is positive
                if (bal > 0) {
                    output.push_back(')');
                    solve(s, ans, open, close, bal - 1, index + 1, output);
                    output.pop_back();
                }
            }
        }
    }

    // Function to remove invalid parentheses and return all possible valid strings
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> ans; // To store unique valid strings
        int invalidOpen = 0;       // Count of invalid open parentheses
        int invalidClosed = 0;     // Count of invalid close parentheses
        int balance = 0;           // Balance of open and close parentheses
        int index = 0;             // Start index
        string output = "";        // Output string to store the result

        // Calculate the number of invalid open and close parentheses
        for (auto ch : s) {
            if (ch == '(') {
                invalidOpen++;
            } else if (ch == ')') {
                if (invalidOpen > 0) {
                    invalidOpen--;
                } else {
                    invalidClosed++;
                }
            }
        }

        // Call the recursive function to generate all valid strings
        solve(s, ans, invalidOpen, invalidClosed, balance, index, output);

        // Convert the unordered_set to a vector and return it
        return vector<string>(ans.begin(), ans.end());
    }
};
