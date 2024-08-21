// leetcode 53. Maximum Subarray

// Given an integer array nums, find the subarray with the largest sum, and return its sum.

#include<iostream>
#include<vector>
using namespace std;

// Method 1 Kadane's Algorithm; 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
              int maxSum = nums[0] ; 
              int n =  nums.size(); 
                  int sum =0 ;
          for(int i = 0 ; i<n ; i++){
              //step : 1 ; 
                sum+=nums[i]; 
              //step : 2 ; 
                maxSum=max(maxSum,sum); 
             //stemp : 3 ; 
                if(sum<0){
                    sum = 0 ; 
                }
          }

          return maxSum; 
    }
};


//Method 2 Using D&C ; 
class Solution {
public:
    int maxSubArrayHelper(vector<int>& nums, int start, int end){
        if (start == end) return nums[start];
        int maxLeftBorderSum = INT_MIN, maxRightBorderSum = INT_MIN;
        int mid = start + (end - start)/2;

        int maxLeftSum = maxSubArrayHelper(nums, start, mid);
        int maxRightSum = maxSubArrayHelper(nums, mid+1, end);

        // max cross border sum
        int leftBorderSum = 0, rightBorderSum = 0;
        for(int i=mid; i>=start; i--){
            leftBorderSum += nums[i];
            if(leftBorderSum > maxLeftBorderSum){
                maxLeftBorderSum = leftBorderSum;
            }
        }
        for(int i=mid+1; i<=end; i++){
            rightBorderSum += nums[i];
            if(rightBorderSum > maxRightBorderSum){
                maxRightBorderSum = rightBorderSum;
            }
        }
        int crossBorderSum = maxLeftBorderSum + maxRightBorderSum;
        return max(maxLeftSum, max(maxRightSum, crossBorderSum));
    }

    int maxSubArray(vector<int>& nums) {
        return maxSubArrayHelper(nums, 0, nums.size()-1);
    }
};

