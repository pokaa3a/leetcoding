#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <unordered_map>
using namespace std;

class Robot {
private:
	int cur_r;
	int cur_c;
	int cur_ori;	// 0: top, 1: right, 2: bot, 3: left
	vector<vector<int> > room;	// 0: blocked, 1: not cleaned, 2: cleaned
	vector<int> r_fwd;
	vector<int> c_fwd;
	int rows;
	int cols;
public:
	Robot(vector<vector<int> > room, int init_r, int init_c, int ori) : 
		cur_r(init_r), cur_c(init_c), room(room) {
		int r_fwd_array[] = {-1, 0, 1, 0};
		int c_fwd_array[] = {0, 1, 0, -1};
		r_fwd = vector<int>(r_fwd_array, r_fwd_array + 4);
		c_fwd = vector<int>(c_fwd_array, c_fwd_array + 4);
		rows = room.size();
		cols = room[0].size();
	}
	bool move() {
		int next_r = cur_r + r_fwd[cur_ori];
		int next_c = cur_c + c_fwd[cur_ori];
		if (next_r >= 0 && next_r < rows && next_c >= 0 && next_c < cols &&
			room[next_r][next_c] != 0) {
			cur_r = next_r;
			cur_c = next_c;
		} else {
			return false;
		}
		return true;
	}
	void turnLeft() {
		cur_ori--;
		if (cur_ori < 0) cur_ori += 4;
	}
	void turnRight() {
		cur_ori = (cur_ori + 1) % 4;
	}
	void clean() {
		// cout << "clean: " << cur_r << ", " << cur_c << endl;
		room[cur_r][cur_c] = 2;
	}
	void showRoom() {
		for (int i = 0; i < room.size(); ++i) {
			for (int j = 0; j < room[i].size(); ++j) {
				cout << room[i][j] << " ";
			}
			cout << endl;
		}
	}
	void curState() {
		cout << "row: " << cur_r << " col: " << cur_c << " ori: " << cur_ori << endl;
	}
};

class Solution {
private:
	vector<int> r_fwd;
	vector<int> c_fwd;
public:
	Solution () {
		int r_fwd_array[] = {-1, 0, 1, 0};
		int c_fwd_array[] = {0, 1, 0, -1};
		r_fwd = vector<int>(r_fwd_array, r_fwd_array + 4);
		c_fwd = vector<int>(c_fwd_array, c_fwd_array + 4);
	}
	void cleanRoom(Robot& robot) {
		set<pair<int, int> > explored;
		dfs(robot, explored, 0, 0, 0);
	}
	void dfs(Robot& robot, set<pair<int, int> >& explored, int r, int c, int ori) {
		robot.clean();
		explored.insert(make_pair(r, c));

		for (int i = 0; i < 4; i++) {
			int next_r = r + r_fwd[ori];
			int next_c = c + c_fwd[ori];
			if (explored.count(make_pair(next_r, next_c)) == 0 && robot.move()) {
				dfs(robot, explored, next_r, next_c, ori);
				// move back
				robot.turnRight();
				robot.turnRight();
				robot.move();
				robot.turnRight();
				robot.turnRight();
			}
			ori = (ori + 1) % 4;
			robot.turnRight();
		}
	}
};

int main() {
	int row0[] = {1,1,1,1,1,0,1,1};
	int row1[] = {1,1,1,1,1,0,1,1};
	int row2[] = {1,0,1,1,1,1,1,1};
	int row3[] = {0,1,0,1,0,0,1,0};
	int row4[] = {1,1,1,1,1,1,1,1};
	vector<vector<int> > room;
	room.push_back(vector<int>(row0, row0 + 8));
	room.push_back(vector<int>(row1, row1 + 8));
	room.push_back(vector<int>(row2, row2 + 8));
	room.push_back(vector<int>(row3, row3 + 8));
	room.push_back(vector<int>(row4, row4 + 8));
	Robot robot(room, 0, 0, 0);
	Solution sol;
	sol.cleanRoom(robot);
	robot.showRoom();
}