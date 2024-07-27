#include <vector>
#include <stack>
#include <cmath> // For abs function
using namespace std;

class Solution {
public:
    /**
     * Function to simulate the collision of asteroids.
     * @param asteroids: A vector of integers representing asteroids, where a positive value indicates a right-moving asteroid and a negative value indicates a left-moving asteroid.
     * @return A vector of integers representing the state of the asteroids after all collisions.
     */
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st; // Stack to keep track of asteroids
        bool destroy = false; // Flag to indicate if an asteroid is destroyed

        // Iterate through each asteroid in the input vector
        for (auto& ast : asteroids) {
            destroy = false; // Reset the destroy flag for each asteroid

            // If the current asteroid is moving right, push it onto the stack
            if (ast > 0) {
                st.push(ast);
            } else {
                // Handle collisions for a left-moving asteroid
                while (!st.empty() && st.top() > 0) {
                    if (abs(ast) == st.top()) {
                        // Both asteroids are equal in size, destroy both
                        destroy = true;
                        st.pop();
                        break;
                    } else if (abs(ast) > st.top()) {
                        // The left-moving asteroid is larger, destroy the right-moving one
                        st.pop();
                    } else {
                        // The right-moving asteroid is larger, destroy the left-moving one
                        destroy = true;
                        break;
                    }
                }

                // If the left-moving asteroid is not destroyed, push it onto the stack
                if (!destroy) {
                    st.push(ast);
                }
            }
        }

        // Prepare the result vector from the stack
        vector<int> ans(st.size());
        for (int i = ans.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};
