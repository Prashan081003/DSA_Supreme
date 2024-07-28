#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    /**
     * Function to simplify an absolute path in Unix-style file system.
     * @param path: The absolute path to be simplified.
     * @return The simplified absolute path.
     */
    string simplifyPath(string path) {
        stack<string> st; // Stack to store directory names
        int i = 0; 
        
        while (i < path.size()) {
            int start = i; // Start of the directory or file name
            int end = i + 1; // End of the directory or file name
            
            // Find the end of the current directory or file name
            while (end < path.size() && path[end] != '/') {
                end++;
            }
            
            // Extract the directory or file name
            string minpath = path.substr(start, end - start);
            i = end; // Move to the next character
            
            // Skip over current directory (".") or redundant slashes ("//")
            if (minpath == "/" || minpath == "/.") continue; 
            
            // If it's not the parent directory (".."), push it to the stack
            else if (minpath != "/..") {
                st.push(minpath);
            } 
            // If it's the parent directory (".."), pop from the stack if it's not empty
            else {
                if (!st.empty()) st.pop();
            }
        }
        
        string ans = "";
        
        // If the stack is empty, return root "/"
        if (st.empty()) return "/";
        
        // Construct the simplified path from the stack
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        
        return ans; // Return the simplified absolute path
    }
};
