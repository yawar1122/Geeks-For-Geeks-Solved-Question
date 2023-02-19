//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        int totalElement = r*c;
        int count = 0;

        vector<int> ans;
        int startingRow = 0;
        int startingCol = 0;
        int endingRow = r - 1;
        int endingCol = c - 1;
        while(count < totalElement){
            //left to right
            for(int index = startingCol ; index<=endingCol && count<totalElement ; index++){
                ans.push_back(matrix[startingRow][index]);
                count++;
            }
            startingRow++;
            //top to bottom
            for(int index = startingRow;index <=endingRow && count < totalElement;index++){
                ans.push_back(matrix[index][endingCol]);
                count++;
            }
            endingCol--;
            //right to left
            for(int index = endingCol;index>=startingCol && count<totalElement ;index--){
                ans.push_back(matrix[endingRow][index]);
                count++;
            }
            endingRow--;
            //bottom to top
            for(int index=endingRow;index>=startingRow && count < totalElement;index--){
                ans.push_back(matrix[index][startingCol]);
                count++;
            }
            startingCol++;
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends