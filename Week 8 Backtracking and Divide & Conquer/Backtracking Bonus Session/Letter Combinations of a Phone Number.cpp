#include <vector>   // Required for using the vector data structure
#include <string>   // Required for using the string class
// 17 ----->> Leetcode ; 

using namespace std;

class Solution {
public:
    // Recursive function to generate letter combinations
    // mapping: array of strings representing the letters for each digit
    // output: current combination being formed
    // index: current index in the input string 'str'
    // ans: vector to store all possible combinations
    // str: input string of digits
    void solve(string mapping[], string output, int index, vector<string>& ans, string str) {
        // Base case: if the index has reached the end of the string
        if (index >= str.size()) {
            // If output is non-empty, add it to the result vector
            if (output.length() > 0)
                ans.push_back(output);
            return;
        }
        
        // Get the possible letters for the current digit
        string temp = mapping[str[index] - '0'];
        for (auto ch : temp) {
            output.push_back(ch); // Add the current letter to the output
            solve(mapping, output, index + 1, ans, str); // Recursively call for the next index
            output.pop_back(); // Backtrack by removing the last added letter
        }
    }

    // Function to return all possible letter combinations for a given string of digits
    vector<string> letterCombinations(string digits) {
        // Mapping of digits to corresponding letters on a phone keypad
        string mapping[] = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        
        string output = ""; // Initialize an empty output string
        int index = 0;      // Start from the first digit
        vector<string> ans; // Vector to store the final combinations
        
        // Call the recursive solve function to generate combinations
        solve(mapping, output, index, ans, digits);
        return ans; // Return the vector of combinations
    }
};
