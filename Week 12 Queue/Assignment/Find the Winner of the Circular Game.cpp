#include <queue>   // Required for using the queue container

class Solution {
public:
    int findTheWinner(int n, int k) {
        std::queue<int> q; // Queue to manage the players
        
        // Initialize the queue with players numbered from 1 to n
        for (int i = 1; i <= n; i++) {
            q.push(i);
        }
        
        // Continue until only one player remains in the queue
        while (q.size() > 1) {
            // Rotate the queue to move the first k-1 players to the back
            for (int i = 1; i < k; i++) {
                int player = q.front(); // Get the player at the front
                q.pop(); // Remove the player from the front
                q.push(player); // Move the player to the back of the queue
            }
            
            // Remove the k-th player (the one to be eliminated)
            q.pop();
        }

        // The last remaining player is the winner
        return q.front(); 
    }
};
