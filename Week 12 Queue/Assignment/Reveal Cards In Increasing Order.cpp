#include <vector>  // Required for using the vector container
#include <queue>   // Required for using the queue container
#include <algorithm>  // Required for using the sort function

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        // Step 1: Sort the deck in increasing order
        std::sort(deck.begin(), deck.end());
        
        // Queue to store the indices of the final positions in the answer
        std::queue<int> q;
        
        // Vector to store the final answer
        std::vector<int> ans(deck.size());

        // Initialize the queue with indices 0 to deck.size()-1
        for (int i = 0; i < ans.size(); i++) {
            q.push(i);
        }

        // Step 2: Simulate the process of revealing cards
        for (int i = 0; i < deck.size(); i++) {
            // 2.1: Place the current smallest card at the front position in the queue
            ans[q.front()] = deck[i];
            q.pop();  // Remove that position from the queue
            
            // 2.2: Move the next index to the bottom of the queue (simulating the "reveal" process)
            if (!q.empty()) {
                int front = q.front();
                q.pop();
                q.push(front);
            }
        }

        // Return the arranged deck in the order cards would be revealed
        return ans;
    }
};
