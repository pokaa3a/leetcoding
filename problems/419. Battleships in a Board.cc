#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int countBattleships(vector<vector<char> > &board) {
		if (board.empty()) return 0;
		int rows = board.size();
		int cols = board[0].size();

		int cnt = 0;
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				if (board[i][j] == 'X'
					&& (i == 0 || board[i - 1][j] != 'X')
					&& (j == 0 || board[i][j - 1] != 'X'))
					cnt++;
			}
		}
		return cnt;
	}
};

int main() {
	char row0[] = {'X', '.', '.', 'X'};
	char row1[] = {'.', '.', '.', 'X'};
	char row2[] = {'.', '.', '.', 'X'};

	vector<vector<char> > board;
	board.push_back(vector<char>(row0, row0 + 4));
	board.push_back(vector<char>(row1, row1 + 4));
	board.push_back(vector<char>(row2, row2 + 4));

	Solution sol;
	cout << sol.countBattleships(board) << endl;
}