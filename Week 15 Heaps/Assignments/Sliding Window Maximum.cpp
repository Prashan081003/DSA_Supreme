You are given an array of integers nums, there is a sliding window of size k 
which is moving from the very left of the array to the very right.
You can only see the k numbers in the window. Each time the sliding
window moves right by one position.

Return the max sliding window.

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
         vector<int>ans; 
           int n = nums.size(); 
               deque<int>dq; 
                // q.push_back = -1 ; 
            for(int i = 0 ; i<k ; i++){
                 int curr = nums[i] ; 
                    while(!dq.empty() &&  nums[dq.back()]<curr){
                     dq.pop_back();
                   }
                   cout<<"This value is going inside : "<<i<<" "; 

              dq.push_back(i); 
            }
            ans.push_back( nums[dq.front()]); 

              for(int i = k ; i<n ; i++){
                //    ans.push_back( nums[dq.front()]); 
                       int curr = nums[i] ; 
                    // Remove if index is greater than k ; 
                    if(i-dq.front()>=k){
                        dq.pop_front();
                    }
                    // Remove if curr number is greater than the front element ;
                     while(!dq.empty() &&  nums[dq.back()]<curr){
                     dq.pop_back();
                   }
                   
                   dq.push_back(i); 
                    ans.push_back( nums[dq.front()]); 
              }
              
              return ans; 
    }
};
