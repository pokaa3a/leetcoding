#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
	int m, n;
	int minFlips(vector<vector<int>>& mat) {
		m = mat.size(), n = mat[0].size();
		
		string init_state = encode(mat);
		queue<string> q;
		unordered_set<string> visited;
		q.push(init_state);
		visited.insert(init_state);

		int steps = 0;
		while (!q.empty()) {
			int q_size = q.size();
			for (int i = 0; i < q_size; i++) {
				vector<vector<int>> cur = decode(q.front());
				q.pop();

				if (allZeros(cur)) return steps;

				for (int i = 0; i < m; i++) {
					for (int j = 0; j < n; j++) {
						flip(cur, i, j);
						string s = encode(cur);
						if (visited.count(s) == 0) {
							visited.insert(s);
							q.push(s);
						}
						flip(cur, i, j);
					}
				}
			}
			steps++;
		}
		return -1;
	}
	bool allZeros(vector<vector<int>>& mat) {
		bool all_zeros = true;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (mat[i][j] != 0) all_zeros = false;
			}
		}
		return all_zeros;
	}

	void printMat(vector<vector<int>>& mat) {
		for (int i = 0; i < mat.size(); i++) {
			for (int j = 0; j < mat[i].size(); j++) {
				cout << mat[i][j] << " ";
			}
			cout << endl;
		}
	}
	void flip(vector<vector<int>>& mat, int r, int c) {
		int cells[] = {-1, 0, 0, 1, 0, -1};
		for (int k = 0; k < 5; k++) {
			int i = cells[k], j = cells[k + 1];
			if (r + i >= 0 && r + i < m && c + j >= 0 && c + j < n) {
				mat[r + i][c + j] ^= 1;
			}
		}
	}
	string encode(vector<vector<int>>& mat) {
		string s = "";
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				s += to_string(mat[i][j]);
			}
		}
		return s;
	}
	vector<vector<int>> decode(string s) {
		int idx = 0;
		vector<vector<int>> mat(m, vector<int>(n, 0));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				mat[i][j] = s[idx++] - '0';
			}
		}
		return mat;
	}
};

int main() {
	vector<vector<int>> mat = {{0,0},{0,1}};
	Solution sol;
	cout << sol.minFlips(mat) << endl;
}