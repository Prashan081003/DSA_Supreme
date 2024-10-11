// You are given a 0-indexed integer array nums consisting of 3 * n elements.

// You are allowed to remove any subsequence of elements of size exactly n from nums.
// The remaining 2 * n elements will be divided into two equal parts:
// The first n elements belonging to the first part and their sum is sumfirst.
// The next n elements belonging to the second part and their sum is sumsecond.
// The difference in sums of the two parts is denoted as sumfirst - sumsecond.
// For example, if sumfirst = 3 and sumsecond = 2, their difference is 1.
// Similarly, if sumfirst = 2 and sumsecond = 3, their difference is -1.
// Return the minimum difference possible between the sums of the two parts after the removal of n elements.


// Example 1:
// Input: nums = [3,1,2]
// Output: -1


class Solution {
public:
      #define ll long long 
    long long minimumDifference(vector<int>& nums) {
         int n  = nums.size()/3;
         vector<ll>prefix(nums.size(),-1), suffix(nums.size(),-1);
           priority_queue<ll>pq;
             ll sum = 0 ; 
         for(int i = 0 ; i<nums.size() ; i++){
                 sum += nums[i];
                   pq.push(nums[i]);
                 if(pq.size()>n){
                    sum-=pq.top();
                    pq.pop();
                 }
                 if(pq.size()==n){
                    prefix[i] =sum;
                 }
         }

         sum =0 ;
         priority_queue<ll,vector<ll>,greater<ll>>pq2;

         for(int i = nums.size()-1 ; i>=0 ; i--){
                 sum += nums[i];
                 pq2.push(nums[i]);
                 if(pq2.size()>n){
                    sum-=pq2.top();
                    pq2.pop();
                 }
                 if(pq2.size()==n){
                    suffix[i] =sum;
                 }
         }

         ll ans = LONG_LONG_MAX; 
         for(int i = n-1 ; i <2*n ; i++ ){
                ans = min(ans, prefix[i]-suffix[i+1]);
         }
         
         return ans;
    }
};
