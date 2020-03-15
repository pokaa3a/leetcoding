class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>> visited(row,vector<bool>(col,false));
        
        int num=0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    num++;
                    search(grid, visited, i, j);
                }
            }
        }
        return num;
    }
    
    void search(vector<vector<char>> &grid, vector<vector<bool>> &visited, int r, int c){
        visited[r][c] = true;
        if(r-1>=0 && grid[r-1][c]=='1' && !visited[r-1][c]){
            search(grid, visited, r-1, c);
        }
        if(r+1<grid.size() && grid[r+1][c]=='1' && !visited[r+1][c]){
            search(grid, visited, r+1, c);
        }
        if(c-1>=0 && grid[r][c-1]=='1' && !visited[r][c-1]){
            search(grid, visited, r, c-1);
        }
        if(c+1<grid[0].size() && grid[r][c+1]=='1' && !visited[r][c+1]){
            search(grid, visited, r, c+1);
        }
    }
};