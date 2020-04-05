#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int m = maze.size(), n = maze[0].size();
        queue<vector<int>> q;
        q.push(start);
        maze[start[0]][start[1]] = 2;
        
        while (!q.empty()) {
            int q_size = q.size();
            for (int i = 0; i < q_size; i++) {
                vector<int> cur = q.front();
                q.pop();
                
                if (cur == destination) return true;
                
                int dirs[] = {-1, 0, 1, 0, -1};
                for (int k = 0; k < 4; k++) {
                    int r = cur[0], c = cur[1];
                    while (r + dirs[k] >= 0 && r + dirs[k] < m &&
                           c + dirs[k + 1] >= 0 && c + dirs[k + 1] < n &&
                           maze[r + dirs[k]][c + dirs[k + 1]] != 1) {
                        r += dirs[k];
                        c += dirs[k + 1];
                    }
                    if (maze[r][c] != 2) {
                        q.push(vector<int>{r, c});
                        maze[r][c] = 2;
                    }
                }
            }
        }
        return false;
    }
};

int main() {
	
}