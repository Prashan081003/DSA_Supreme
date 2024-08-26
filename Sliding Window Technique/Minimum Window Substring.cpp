#include <string>           // Required for using std::string
#include <unordered_map>    // Required for using std::unordered_map
#include <climits>          // Required for using INT_MAX

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int len1 = s.length(); // Length of the source string
        int len2 = t.length(); // Length of the pattern string
        
        // If the source string is shorter than the pattern, return an empty string
        if (len1 < len2) return "";

        int start = 0;          // Start index of the current window
        int ansIndex = -1;      // Start index of the minimum window found
        int ansLen = INT_MAX;   // Length of the minimum window found

        // Maps to store the frequency of characters in source and pattern strings
        unordered_map<char, int> sMap;  // Frequency map for source string
        unordered_map<char, int> tMap;  // Frequency map for pattern string
        
        // Store the frequency of each character in the pattern string
        for (char ch : t) {
            tMap[ch]++;
        }

        int count = 0;  // Number of characters matched with the pattern
        int e = 0;      // End index of the current window

        // Sliding window approach
        while (e < s.length()) {
            char ch = s[e];  // Current character at the end of the window
            sMap[ch]++;      // Increase the frequency of the character in the source map

            // If the character count in sMap is less than or equal to that in tMap, it is part of the valid window
            if (sMap[ch] <= tMap[ch]) {
                count++;
            }

            // When all characters in t are matched, try to minimize the window
            if (count == len2) {
                // Shrink the window from the start if possible
                while (sMap[s[start]] > tMap[s[start]] || tMap[s[start]] == 0) {
                    if (sMap[s[start]] > tMap[s[start]]) {
                        sMap[s[start]]--;
                    }
                    start++;
                }

                // Calculate the current window length
                int windowLength = e - start + 1;
                // Update the minimum window length and starting index
                if (windowLength < ansLen) {
                    ansLen = windowLength;
                    ansIndex = start;
                }
            }

            e++;  // Expand the window from the end
        }

        // If no valid window is found, return an empty string; otherwise, return the minimum window substring
        if (ansIndex == -1) {
            return "";
        } else {
            return s.substr(ansIndex, ansLen);
        }
    }
};
