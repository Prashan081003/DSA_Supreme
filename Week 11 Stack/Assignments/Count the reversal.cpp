#include <stack>
#include <string>
using namespace std;

int countRev(string s) {
    int n = s.size();
    if (n % 2 != 0) return -1; // If the length of the string is odd, it's impossible to balance

    stack<char> st;
    int ans = 0;

    // Traverse the string
    for (int i = 0; i < n; i++) {
        char ch = s[i];
        if (ch == '{') {
            st.push(ch);
        } else {
            if (!st.empty() && st.top() == '{') {
                st.pop(); // Valid pair found, pop the top
            } else {
                st.push(ch); // Unmatched closing brace
            }
        }
    }

    // Process remaining elements in the stack
    while (!st.empty()) {
        char a = st.top(); st.pop();
        char b = st.top(); st.pop();
        
        if (a == b) {
            ans += 1; // Two same type braces need 1 reversal
        } else {
            ans += 2; // Two different type braces need 2 reversals
        }
    }

    return ans;
}
