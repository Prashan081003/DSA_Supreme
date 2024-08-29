#include <vector>   // Required for using the vector data structure
#include <string>   // Required for using the string class
#include <algorithm> // Optional: For using algorithms like sort (if needed later)

using namespace std;
//1079---->>>Leetcode; 
class Solution {
public:
    // Function to solve the problem using recursion
    // freq: vector containing the frequency of each character in the string
    int solve(vector<int>& freq) {
        int ans = 0;
        
        // Iterate over all possible characters (26 uppercase letters)
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) {
                ans++; // Increment the count as a new sequence is possible
                
                freq[i]--; // Decrease the frequency of the current character
                int recursionKaAns = solve(freq); // Recursive call to solve for the remaining characters
                ans += recursionKaAns; // Add the result from the recursive call to the answer
                freq[i]++; // Backtrack by restoring the frequency of the current character
            }
        }
        
        return ans; // Return the total number of possible sequences
    }

    // Function to calculate the number of tile possibilities
    // tiles: the input string of tiles
    int numTilePossibilities(string tiles) {
        vector<int> freq(26, 0); // Initialize frequency vector for 26 letters (A-Z)

        // Calculate the frequency of each character in the input string
        for (auto ch : tiles) {
            freq[ch - 'A']++;
        }
        
        return solve(freq); // Call the recursive solve function with the frequency vector
    }
};
