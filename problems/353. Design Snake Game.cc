#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

class SnakeGame {
public:
	SnakeGame(int width, int height, vector<vector<int> >& food) {
		row_bnd_ = make_pair(-1, height);
		col_bnd_ = make_pair(-1, width);
		food_ = food;
		food_idx_ = 0;
		snake_q_.push(make_pair(0, 0));
		snake_s_.insert(make_pair(0, 0));
		score = 0;
	}
	int move(string direction) {
		// cout << "move: " << direction << endl;
		pair<int, int> next_pos;
		pair<int, int> cur_pos = snake_q_.back();
		if (direction == "U") {
			next_pos = make_pair(cur_pos.first - 1, cur_pos.second);
		} else if (direction == "D") {
			next_pos = make_pair(cur_pos.first + 1, cur_pos.second);
		} else if (direction == "L") {
			next_pos = make_pair(cur_pos.first, cur_pos.second - 1);
		} else {	// direction == "R"
			next_pos = make_pair(cur_pos.first, cur_pos.second + 1);
		}

		// check if eating food
		if (food_idx_ < food_.size() &&
			next_pos == make_pair(food_[food_idx_][0], food_[food_idx_][1])) {
			score++;
			food_idx_++;
		} else {
			snake_s_.erase(snake_q_.front());
			snake_q_.pop();
		}

		// check if biting itself
		if (snake_s_.find(next_pos) != snake_s_.end()) {
			// cout << "EATS ITSELF!" << endl;
			return -1;
		}
		// check if collision with borders
		if (next_pos.first == row_bnd_.first || 
			next_pos.first == row_bnd_.second ||
			next_pos.second == col_bnd_.first ||
			next_pos.second == col_bnd_.second) {
			// cout << "COLLISION!" << endl;
			return -1;
		}
		snake_q_.push(next_pos);
		snake_s_.insert(next_pos);

		// for (int i = 0; i < row_bnd_.second; ++i) {
		// 	for (int j = 0; j < col_bnd_.second; ++j) {
		// 		if (snake_s_.find(make_pair(i, j)) != snake_s_.end()) {
		// 			cout << "S" << " ";
		// 		} else if (i == food_[food_idx_][0] && j == food_[food_idx_][1]) {
		// 			cout << "F" << " ";
		// 		} else {
		// 			cout << "_" << " ";
		// 		}
		// 	}
		// 	cout << endl;
		// }

		return score;
	}

private:
	vector<vector<int> > food_;
	int food_idx_;
	queue<pair<int, int> > snake_q_;	// record the snake's body
	set<pair<int, int> > snake_s_;		// for checking the snake bites itself
	pair<int, int> row_bnd_;
	pair<int, int> col_bnd_;
	int score;
};

int main() {
	int width = 3;
	int height = 3;
	vector<vector<int> > food;
	int f1[] = {2, 0};
	int f2[] = {0, 0};
	int f3[] = {0, 2};
	int f4[] = {2, 2};
	food.push_back(vector<int>(f1, f1 + 2));
	food.push_back(vector<int>(f2, f2 + 2));
	food.push_back(vector<int>(f3, f3 + 2));
	food.push_back(vector<int>(f4, f4 + 2));
	SnakeGame *snake = new SnakeGame(width, height, food);

	cout << snake->move("D") << endl;
	cout << snake->move("D") << endl;
	cout << snake->move("R") << endl;
	cout << snake->move("U") << endl;
	cout << snake->move("U") << endl;
	cout << snake->move("L") << endl;
	cout << snake->move("D") << endl;
	cout << snake->move("R") << endl;
	cout << snake->move("R") << endl;
	cout << snake->move("U") << endl;
	cout << snake->move("L") << endl;
	cout << snake->move("D") << endl;
}