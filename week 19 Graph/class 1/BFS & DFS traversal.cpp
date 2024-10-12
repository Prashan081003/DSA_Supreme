
    void bfsTraversal(T src,unordered_map< T, bool>& vis) {
      //adjList alrady data member me hai 
      //visited
      
      //queue
      queue<T> q;

      //initial state
      q.push(src);
      vis[src] =true;

      while(!q.empty()) {
        T frontNode = q.front();
        cout << frontNode << " ";
        q.pop();

        //go to nbr
        for(auto nbr: adjList[frontNode]) {
          T nbrData = nbr.first;

          if(!vis[nbrData]) {
            q.push(nbrData);
            vis[nbrData] = true;
          }
        }
      }

    }

    void dfs(T src, unordered_map<T,bool>& vis ) {
      vis[src] = true;
      cout << src << " ";

      for(auto nbr: adjList[src]) {
        T nbrData = nbr.first;
        if(!vis[nbrData]) {
          dfs(nbrData, vis);
        }
      }
    }

};

int main() {
//   Graph g;
//   g.addEdge(0,1,0);
//   g.addEdge(1,2,0);
//   g.addEdge(1,3,0);
//   g.addEdge(2,3,0);

  Graph<char> g;
 // cout << "HII" << endl;
  g.addEdge('a','b',5,0);
  //g.addEdge('a','c',10,0);
  g.addEdge('c','d',20,0);
  g.addEdge('c','e',50,0);
  g.addEdge('d','e',20,0);
  g.addEdge('e','f',50,0);

  unordered_map<char, bool> visited;
  //g.dfs('a',visited);
  for(char node='a'; node<='f'; node++) {
    if(!visited[node]) {
        g.dfs(node, visited);
    }
  }
  //HW: find out number of disconnected components in a graph
  

//   unordered_map<char, bool> vis;
//   for(char node='a'; node<='f'; node++) {
//       if(!vis[node] ) {
//         g.bfsTraversal(node,vis);
//       }
//   }

  
  return 0;
}
