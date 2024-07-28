#include <string>
#include <stack>
#include <cctype> // For isdigit
using namespace std;

class Solution {
public:
    /**
     * Function to decode a given encoded string.
     * @param s: The encoded string.
     * @return The decoded string.
     */
    string decodeString(string s) {
        stack<string> st; // Stack to store characters and decoded parts of the string

        // Traverse each character in the input string
        for (auto ch : s) {
            if (ch == ']') { // When we encounter a closing bracket
                string stringToRepeat = "";
                // Retrieve the substring to be repeated
                while (!st.empty() && st.top() != "[") {
                    stringToRepeat = st.top() + stringToRepeat;
                    st.pop();
                }
                st.pop(); // Pop the opening bracket '['
                
                string numericTimes = "";
                // Retrieve the number of times to repeat the substring
                while (!st.empty() && isdigit(st.top()[0])) {
                    numericTimes = st.top() + numericTimes;
                    st.pop();
                }

                int n = stoi(numericTimes); // Convert the numeric string to an integer

                string currentDecode = "";
                // Repeat the substring 'n' times
                while (n--) {
                    currentDecode += stringToRepeat;
                }
                st.push(currentDecode); // Push the repeated substring back to the stack
            } else {
                // Push the current character as a string to the stack
                string temp(1, ch);
                st.push(temp);
            }
        }

        string ans;
        // Retrieve the final decoded string from the stack
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }

        return ans; // Return the final decoded string
    }
};
