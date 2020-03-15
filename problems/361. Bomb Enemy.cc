class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
		int rows = grid.size();
		if(rows==0) return 0;
		int cols = grid[0].size();
		if(cols==0) return 0;

		vector<vector<int> > count(rows, vector<int>(cols, 0));

		for(int i=0; i<rows; i++){
			for(int head=0, tail=0, j=0; j<cols; j++){
				count[i][j] = grid[i][j]=='0'? head+count[i][j]:0;
				count[i][cols-1-j] = grid[i][cols-1-j]=='0'? tail+count[i][cols-1-j]:0;
				head = grid[i][j]=='W'? 0:head+(grid[i][j]=='E'?1:0);
				tail = grid[i][cols-1-j]=='W'? 0:tail+(grid[i][cols-1-j]=='E'?1:0);
			}
		}
		for(int j=0; j<cols; j++){
			for(int head=0, tail=0, i=0; i<rows; i++){
				count[i][j] = grid[i][j]=='0'? head+count[i][j]:0;
				count[rows-1-i][j] = grid[rows-1-i][j]=='0'? tail+count[rows-1-i][j]:0;
				head = grid[i][j]=='W'? 0:head+(grid[i][j]=='E'?1:0);
				tail = grid[rows-1-i][j]=='W'? 0:tail+(grid[rows-1-i][j]=='E'?1:0);
			}
		}
		int res = 0;
		for(int i=0; i<rows; i++){
			for(int j=0; j<cols; j++){
				res = max(res, count[i][j]);
			}
		}
		return res;
    }
};