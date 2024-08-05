
// Problem Summary
// You need to implement a class RecentCounter that counts the number of recent requests within 
// a certain time frame (3000 milliseconds). The ping method receives the current timestamp and
// returns the number of pings in the last 3000 milliseconds.

#include <iostream>
#include <queue>

using namespace std;

class RecentCounter {
public:
    queue<int> q; // Queue to store the timestamps of the pings
    
    RecentCounter() {
        // Constructor doesn't need any initialization
    }
    
    int ping(int t) {
        q.push(t); // Push the current timestamp into the queue
        
        // Remove timestamps that are older than 3000 milliseconds from the current timestamp
        while (!q.empty() && q.front() < t - 3000) {
            q.pop();
        }
        
        // The size of the queue now represents the number of pings in the last 3000 milliseconds
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
