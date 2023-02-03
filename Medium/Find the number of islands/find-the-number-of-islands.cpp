//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
   void bfs(int row, int col, vector<vector<int>> &visited, vector<vector<char>> grid){
       int n = grid.size();
       int m = grid[0].size();
       
       visited[row][col] = 1;
       
       queue<pair<int,int>> q;
       q.push({row,col});
       
       while(!q.empty()){
           int arow = q.front().first;
           int acol = q.front().second;
           q.pop();
           
           //traverse in the neighbours and mark them if its land
           
           for(int delrow = -1;delrow<=1;delrow++){
                for(int delcol = -1;delcol<=1;delcol++){
                    int nrow = arow + delrow;
                    int ncol = acol + delcol;
                    
                    if( nrow >= 0 && nrow < n
                        && ncol >=0 && ncol < m
                        && grid[nrow][ncol] == '1'
                        && !visited[nrow][ncol]
                    )
                    {
                        visited[nrow][ncol] = 1;
                        q.push({nrow,ncol});
                    }
                }
               
           }
           
       }
       
   }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> visited(n,vector<int>(m,0));
        int count = 0;
        
        for(int row = 0; row < n; row++){
            for(int col = 0;col<m;col++){
                if(grid[row][col] == '1' && !visited[row][col]){
                    count++;
                    bfs(row,col,visited,grid);
                }
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends