#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	void gameOfLife(vector<vector<int> >& board){
		int rows = board.size();
		int cols = rows!=0?board[0].size():0;

		for(int i=0; i<rows; i++){
			for(int j=0; j<cols; j++){
				int count = 0;
				for(int x=max(i-1,0); x<=min(i+1,rows-1); x++){
					for(int y=max(j-1,0); y<=min(j+1,cols-1); y++){
						count += board[x][y]&1;
					}
				}
				if(count==3 || count-board[i][j]==3){
					board[i][j] |= 2;
				}
			}
		}
		for(int i=0; i<rows; i++){
			for(int j=0; j<cols; j++){
				board[i][j]>>1;
			}
		}
	}
}

int main(){

}