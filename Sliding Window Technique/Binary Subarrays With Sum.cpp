class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size(); 
         int s = 0 ;
          int e = 0 ;
           int prefixZero = 0 ,count=0 ; 
             int sum = 0 ; 
           while(e<nums.size()){
               sum = sum + nums[e] ; 
               //mimimize
               while(s<e && (sum>goal || nums[s]==0)){
                   //ans; 
                   if(nums[s]==1){
                    prefixZero = 0 ; 

                   }
                   else{
                     prefixZero+=1 ;
                   }
                   sum-=nums[s]; 
                   s++ ; 

               }
               //verification 
               if(sum==goal){
                 count+=prefixZero+1 ; 
               }
               e++;
    }
           
        return  count; 
    }
};
