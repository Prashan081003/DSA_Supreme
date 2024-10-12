// detect cycle in an undirected graph

#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
using namespace std;

   //=====>>> below function code is CGPT generated code  <<<==========
bool bfs(int start, vector<int>& visited, vector<vector<int>>& adj) {
    queue<pair<int, int>> q;  // Pair holds {node, parent}
    visited[start] = 1;
    q.push({start, -1});

    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                q.push({neighbor, node});
            } else if (neighbor != parent) {
                return true;  // Cycle detected
            }
        }
    }

    return false;
}

//=======>> This is Love Babbar Bhaiya's Code taught in class <<========
    bool checkCycleUndirectedBFS(int src){
        queue<int> q;
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;
        // initial state
        q.push(src);
        visited[src] = true;
        parent[src] = -1;
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            for(auto nbr: adjLIst[frontNode]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = frontNode;
                }
                else if(visited[nbr] == true && nbr != parent[frontNode]){
                    // cycle present
                    return true;
                }
            }
        }
        // cycle not present
        return false;
    }
};

//------------>>  below is the question solved in gfg of detect cycle in undirected grapH ------------->>
bool isCycle(int V, vector<int> adj[]) {
    // Using vector instead of unordered_map for visited and parent
    vector<bool> vis(V, false); 
    vector<int> parent(V, -1);
    
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            // Perform BFS for each unvisited component
            queue<int> q;
            q.push(i);
            vis[i] = true;
            parent[i] = -1;  // The starting node has no parent
            
            while (!q.empty()) {
                int frontNode = q.front();
                q.pop();
                
                // Explore all the neighbors of frontNode
                for (auto nbr : adj[frontNode]) {
                    if (!vis[nbr]) {
                        // If not visited, mark it and assign parent
                        q.push(nbr);
                        vis[nbr] = true;
                        parent[nbr] = frontNode;
                    }
                    // If visited and it's not the parent, there's a cycle
                    else if (vis[nbr] == true && nbr != parent[frontNode]) {
                        return true;  // Cycle detected
                    }
                }
            }
        }
    }
    
    return false;  // No cycle found in any component
}

