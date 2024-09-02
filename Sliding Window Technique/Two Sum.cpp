//    Leetcode-- 1 ====> Easy ; 

//<<<<===========  Method 1 ================ using custom sortin =========>>>>>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> vec; // Pair to store (index, value)
        vector<int> ans;
        
        // Fill the vector with pairs of (index, value)
        for (int i = 0; i < nums.size(); i++) {
            vec.push_back({i, nums[i]});
        }
        
        // Custom sort: sort by value in ascending order
        sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second; // Compare based on the value
        });
        
        int s = 0, e = nums.size() - 1;
        
        // Use two-pointer technique to find the two values that add up to the target
        while (s < e) {
            int sum = vec[s].second + vec[e].second; // Sum the values
            if (sum == target) {
                ans.push_back(vec[s].first); // Store the original indices
                ans.push_back(vec[e].first);
                return ans;
            }
            else if (sum > target) {
                e--;
            }
            else {
                s++;
            }
        }
        
        return ans; // Return an empty vector if no solution is found
    }
};
//Method 2 ===========  without custom sorting ===========>>>>>>>>>>>>
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
