#include <vector>  // Required for using the vector container
#include <stack>   // Required for using the stack container
#include <algorithm> // Required for using the max function
#include <climits>   // Required for using INT_MIN

using namespace std;

class Solution {
public:
    // Function to find the next smaller element for each element in the array
    vector<int> nextSmallerElement(vector<int>& arr) {
        vector<int> ans(arr.size()); // Vector to store the result
        stack<int> st; // Stack to keep track of indices of elements
        st.push(-1); // Initial condition: -1 as the base for comparison

        // Traverse the array from right to left
        for(int i = arr.size() - 1; i >= 0; i--) {
            int curr = arr[i]; // Current element
            // Pop elements from the stack until a smaller element is found
            while(st.top() != -1 && arr[st.top()] >= curr) {
                st.pop();
            }
            ans[i] = st.top(); // Store the index of the next smaller element
            st.push(i); // Push current index onto the stack
        }
        return ans;
    }

    // Function to find the previous smaller element for each element in the array
    vector<int> prevSmallerElement(vector<int>& arr) {
        vector<int> ans(arr.size()); // Vector to store the result
        stack<int> st; // Stack to keep track of indices of elements
        st.push(-1); // Initial condition: -1 as the base for comparison

        // Traverse the array from left to right
        for(int i = 0; i < arr.size(); i++) {
            int curr = arr[i]; // Current element
            // Pop elements from the stack until a smaller element is found
            while(st.top() != -1 && arr[st.top()] >= curr) {
                st.pop();
            }
            ans[i] = st.top(); // Store the index of the previous smaller element
            st.push(i); // Push current index onto the stack
        }
        return ans;
    }

    // Function to find the largest rectangular area in a histogram
    int largestRectangleArea(vector<int>& heights) {
        vector<int> next = nextSmallerElement(heights); // Next smaller elements
        vector<int> prev = prevSmallerElement(heights); // Previous smaller elements

        // Adjust the next smaller element values for correct width calculation
        for(int i = 0; i < next.size(); i++) {
            if(next[i] == -1) {
                next[i] = next.size(); // If no smaller element, assume beyond the array
            }
        }

        int maxArea = INT_MIN; // Variable to store the maximum area

        // Calculate the area for each element as the height of a potential rectangle
        for(int i = 0; i < heights.size(); i++) {
            int length = heights[i]; // Height of the rectangle
            int width = next[i] - prev[i] - 1; // Width of the rectangle
            int currArea = length * width; // Area of the rectangle
            maxArea = max(maxArea, currArea); // Update the maximum area
        }

        return maxArea; // Return the largest rectangle area found
    }

    // Function to find the maximal rectangle of 1's in a binary matrix
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0; // Handle edge case: empty matrix

        int n = matrix.size(); // Number of rows in the matrix
        int m = matrix[0].size(); // Number of columns in the matrix
        vector<vector<int>> v(n, vector<int>(m, 0)); // Initialize a 2D vector to store int values

        // Convert the input matrix from char to int
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                v[i][j] = matrix[i][j] - '0'; // Convert char '0' or '1' to int 0 or 1
            }
        }

        int area = largestRectangleArea(v[0]); // Calculate area using the first row as a histogram

        // Iterate over the rows to calculate the maximal rectangle area
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(v[i][j] != 0) {
                    v[i][j] += v[i-1][j]; // Add the value from the previous row to form a new histogram
                } else {
                    v[i][j] = 0; // Reset to 0 if the current cell is 0
                }
            }
            area = max(area, largestRectangleArea(v[i])); // Update the maximum area found
        }

        return area; // Return the maximum rectangle area in the matrix
    }
};
