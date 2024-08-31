// Leetcode  =========  209 ( Medium) ======== //
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
            int len = INT_MAX ; 
                int currSum =0 ; 
                  int s=0 ,e =0 ; 
                     int sum = 0 ; 

             while(e<nums.size()){
                 //sum me include karo value
                 sum+=nums[e];
                 //ho skta hai ,sum==target 
                  //ho skta hai ,sum>target  
                  //ho skta hai ,sum<target 

                  //minimise->equal or greater
                  //explore ->lesser

                  while(sum>=target){
                     //minimise
                     len = min(len,e-s+1);
                     sum-=nums[s]; 
                     s++ ; 
                  }
                e++; 
             }

            return len==INT_MAX?0:len; 
    }
};
