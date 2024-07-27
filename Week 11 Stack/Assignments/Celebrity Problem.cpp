#include <vector>
#include <stack>
using namespace std;

class Solution {
  public:
    /**
     * Function to find if there is a celebrity in the party or not.
     * @param M: A 2D vector representing the acquaintance matrix where M[i][j] is 1 if person i knows person j, otherwise 0.
     * @param n: The number of people at the party.
     * @return The index of the celebrity if there is one, otherwise -1.
     */
    int celebrity(vector<vector<int>>& M, int n) {
        stack<int> st;

        // Push all the people onto the stack.
        for (int i = 0; i < n; i++) {
            st.push(i);
        }

        // Determine the potential celebrity.
        while (st.size() > 1) {
            int a = st.top(); st.pop();
            int b = st.top(); st.pop();

            // If person a knows person b, then a cannot be a celebrity.
            if (M[a][b]) {
                st.push(b);
            } else {
                // If person a does not know person b, then b cannot be a celebrity.
                st.push(a);
            }
        }

        // The potential celebrity.
        int celeb = st.top(); st.pop();

        // Check if the potential celebrity does not know anyone.
        for (int i = 0; i < n; i++) {
            if (M[celeb][i] != 0) return -1;
        }

        // Check if everyone knows the potential celebrity.
        for (int i = 0; i < n; i++) {
            if (M[i][celeb] == 0 && i != celeb) return -1;
        }

        return celeb;
    }
};
