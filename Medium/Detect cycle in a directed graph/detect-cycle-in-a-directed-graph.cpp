//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    bool cycle(int node, int visited[],int pathVisited[],vector<int> adj[]){
        visited[node] = 1;
        pathVisited[node] = 1;
        
        //traversing the graph
        for(auto it:adj[node]){
            
            //whent the node is not visited
            if(!visited[it]){
                if(cycle(it,visited,pathVisited,adj)==true){
                    return true;
                }
                
            }
            //if the node has been previously visited
            //but it has to be visited on the same path
            else if(pathVisited[it]){
                return true;
            }
        }
        pathVisited[node] = 0;
        return false;
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int visited[V] = {0};
        int pathVisited[V] = {0};
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(cycle(i,visited,pathVisited,adj)==true){
                    return true;
                }
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends