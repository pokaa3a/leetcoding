#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class TicTacToe {
private:
	unordered_map<int, int> horizontal_p1;
	unordered_map<int, int> vertical_p1;
	int left_diagonal_p1;
	int right_diagonal_p1;
	unordered_map<int, int> horizontal_p2;
	unordered_map<int, int> vertical_p2;
	int left_diagonal_p2;
	int right_diagonal_p2;	
	int size;
public:
	TicTacToe(int n) {
		size = n;
		left_diagonal_p1 = 0;
		right_diagonal_p1 = 0;
		left_diagonal_p2 = 0;
		right_diagonal_p2 = 0;
	}
	int move(int row, int col, int player) {
		if (player == 1) {
			// cout << "horizontal_p1: " << horizontal_p1[row] + 1 << endl;
			// cout << "vertical_p1: " << vertical_p1[col] + 1 << endl;
			if (++horizontal_p1[row] == size) return player;
			if (++vertical_p1[col] == size) return player;
			if (row == col) {
				if (++left_diagonal_p1 == size) return player;
			}
			if (row + col == size - 1) {
				if (++right_diagonal_p1 == size) return player;
			}
		} else {
			// cout << "horizontal_p2: " << horizontal_p2[row] + 1 << endl;
			// cout << "vertical_p2: " << vertical_p2[col] + 1 << endl;
			if (++horizontal_p2[row] == size) return player;
			if (++vertical_p2[col] == size) return player;
			if (row == col) {
				if (++left_diagonal_p2 == size) return player;
			}
			if (row + col == size - 1) {
				if (++right_diagonal_p2 == size) return player;
			}
		}
		return 0;
	}
};

int main() {
	TicTacToe toe(3);
	cout << toe.move(0, 0, 1) << endl;
	cout << toe.move(0, 2, 2) << endl;
	cout << toe.move(2, 2, 1) << endl;
	cout << toe.move(1, 1, 2) << endl;
	cout << toe.move(2, 0, 1) << endl;
	cout << toe.move(1, 0, 2) << endl;
	cout << toe.move(2, 1, 1) << endl;

}