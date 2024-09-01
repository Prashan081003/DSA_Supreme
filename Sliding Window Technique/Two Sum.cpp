//    Leetcode-- 1 ====> Easy ; 

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // sort(target.begin(),target.end()); 
               int n = nums.size(); 
                vector<int>ans; 
           vector<pair<int,int>>temp; 
           for(int i = 0; i<n ; i++ ){
                 int index = i ; 
                 int value =  nums[i]; 
                 pair<int,int>p= make_pair(value,index); 
                 temp.push_back(p); 
           }
           sort(temp.begin(),temp.end()); 
         
          //logic 
           int s = 0 ,e =n-1 ; 
          int sum =0;  
          while(s<e){
            int sum = temp[s].first + temp[e].first ; 
            if(sum==target){
                ans.push_back(temp[s].second); 
                ans.push_back(temp[e].second); 
                return ans; 
            }
            else if(sum>target){
                e--;
            }
            else{
                s++; 
            }
          }
        return ans; 
    }
};
