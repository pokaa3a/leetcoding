#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution{
public:
	void solve(vector<vector<char> >& board){
		height = board.size();
		if(height == 0) return;
		width = board[0].size();
		if(width == 0) return;

		// top
		for(int i=0; i<width; ++i){
			if(board[0][i] == 'O' && must_be_O.count(make_pair(0, i)) == 0){
				explore(0, i, board);
			}
		}
		// bot
		for(int i=0; i<width; ++i){
			if(board[height-1][i] == 'O' && must_be_O.count(make_pair(height-1, i)) == 0){
				explore(height-1, i, board);
			}
		}
		// left
		for(int i=0; i<height; ++i){
			if(board[i][0] == 'O' && must_be_O.count(make_pair(i, 0)) == 0){
				explore(i, 0, board);
			}
		}
		// right
		for(int i=0; i<height; ++i){
			if(board[i][width-1] == 'O' && must_be_O.count(make_pair(i, width-1)) == 0){
				explore(i, width-1, board);
			}
		}

		bool debug = true;
		if(debug){
			for(set<pair<int, int> >::iterator it = must_be_O.begin(); it != must_be_O.end(); ++it){
				cout << "(" << it->first << ", " << it->second << ")" << endl;
			}
		}

		for(int i=0; i<height; ++i){
			for(int j=0; j<width; ++j){
				board[i][j] = 'X';
			}
		}
		for(set<pair<int, int> >::iterator it = must_be_O.begin(); it != must_be_O.end(); ++it){
			board[it->first][it->second] = 'O';
		}
	}
	void explore(int row, int col, vector<vector<char> >& board){
		if(must_be_O.count(make_pair(row, col))>0){
			return;
		}
		must_be_O.insert(make_pair(row, col));
		// top
		if(row-1 >= 0 && board[row-1][col] == 'O'){
			explore(row-1, col, board);
		}
		// bot
		if(row+1 < height && board[row+1][col] == 'O'){
			explore(row+1, col, board);
		}
		// left
		if(col-1 >=0 && board[row][col-1] == 'O'){
			explore(row, col-1, board);
		}
		// right
		if(col+1 < width && board[row][col+1] == 'O'){
			explore(row, col+1, board);
		}
	}
private:
	int height;
	int width;
	set<pair<int ,int> > must_be_O;
};

int main(){
	vector<vector<char> > board;
	int row0_array[] = {'X','O','X','X'};
	vector<char> row0(row0_array, row0_array+4);
	int row1_array[] = {'X','O','X','X'};
	vector<char> row1(row1_array, row1_array+4);
	int row2_array[] = {'X','X','O','X'};
	vector<char> row2(row2_array, row2_array+4);
	int row3_array[] = {'X','O','X','X'};
	vector<char> row3(row3_array, row3_array+4);

	board.push_back(row0);
	board.push_back(row1);
	board.push_back(row2);
	board.push_back(row3);

	Solution sol;
	sol.solve(board);

	for(int i=0; i<board.size(); ++i){
		for(int j=0; j<board[0].size(); ++j){
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}