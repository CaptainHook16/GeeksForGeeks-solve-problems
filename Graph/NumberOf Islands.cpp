class Solution {
public:
    int IsSafe(vector<vector<char>>& grid,int i,int j,vector<vector<int>>& visited){
        int m = grid.size();
        int n = grid[0].size();
        if(i<m && j<n && i>=0 && j>=0 && visited[i][j]==0 && grid[i][j]=='1')
            return 1;
        else
            return 0;
    }
    
    void DFS(vector<vector<char>>& grid,int i,int j,vector<vector<int>>& visited){
        static int rowNbr[] ={-1,1,0,0};
        static int colNbr[] = {0,0,1,-1};
        visited[i][j] = 1;
        for(int k=0;k<4;++k){
            if(IsSafe(grid,i+rowNbr[k],j+colNbr[k],visited)){
                DFS(grid,i+rowNbr[k],j+colNbr[k],visited);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid)
    {
        int m = grid.size();
        if(m==0)
            return 0;
        int n = grid[0].size();        
        vector<vector<int>> visited;
        for(int i=0;i<m;i++){
            vector<int> v;
            for(int j=0;j<n;j++){
                v.push_back(0);
            }
            visited.push_back(v);
        }
        
        int count = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] =='1' && !visited[i][j]){
                    DFS(grid,i,j,visited);;
                    count++;
                }
            }
        }
        return count;
    }
};
