//Leetcode 2149 ===============>> Doubt Class Question 
// You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

// You should return the array of nums such that the the array follows the given conditions:

// Every consecutive pair of integers have opposite signs.
// For all integers with the same sign, the order in which they were present in nums is preserved.
// The rearranged array begins with a positive integer.
// Return the modified array after rearranging the elements to satisfy the aforementioned conditions.



class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
          // Method  Two pointer
        vector<int>ans(nums.size(), -1);
        int odd = 1, even = 0;
        for(int i=0;i<nums.size();++i){
            int num = nums[i];
            if(num > 0){
                ans[even] = num;
                even += 2;
            }
            else{
                ans[odd] = num;
                odd+=2;
            }
        }
        return ans;
    }
};
