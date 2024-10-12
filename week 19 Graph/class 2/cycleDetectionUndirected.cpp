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

int main(){
    Graph g;
    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(1, 3, 0);
    g.addEdge(2, 4, 0);
    g.addEdge(3, 4, 0);
    g.addEdge(2, 5, 0);

    int src = 0;
    bool isCyclic = g.checkCycleUndirectedBFS(src);
    if(isCyclic){
        cout<<"cycle present"<<endl;
    }
    else{
        cout<<"cycle absent"<<endl;
    }
    
    return 0;
}
