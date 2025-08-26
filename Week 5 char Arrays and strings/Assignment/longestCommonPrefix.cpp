// leetcode 14. Longest Common Prefix

// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

=========>>>>> New Method <<<<<<======
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string result = strs[0];
        int n = strs.size();

        for (int i = 1; i < n; i++) {
            string temp = "";
            int j = 0;

            // Compare characters of result and strs[i]
            while (j < result.size() && j < strs[i].size() && result[j] == strs[i][j]) {
                temp += result[j];
                j++;
            }

            result = temp;

            // Early exit if no common prefix
            if (result.empty()) return "";
        }

        return result;
    }
};


===========>>>>>> OLD MEthod <<<<<<=============

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        int i = 0;
        while(true){
            char curr_ch = 0;
            for(auto str : strs){
                if(i >= str.size()){
                    // out of bound
                    curr_ch = 0;
                    break;
                }
                // just started
                if(curr_ch == 0){
                    curr_ch = str[i];
                }
                else if(str[i] != curr_ch){
                    curr_ch = 0;
                    break;
                }
            }
            if(curr_ch == 0){
                break;
            }
            ans.push_back(curr_ch);
            i++;
        }
        return ans;
    }
};
