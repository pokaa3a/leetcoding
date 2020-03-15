#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int minimumSemesters(int N, vector<vector<int> >& relations) {
		vector<int> courses(N + 1, 0);
		unordered_map<int, vector<int> > rel;
		queue<int> q;

		for (int i = 0; i < relations.size(); ++i) {
			int x = relations[i][0];
			int y = relations[i][1];
			courses[y]++;
			rel[x].push_back(y);
		}
		for (int i = 1; i < courses.size(); ++i) {
			if (courses[i] == 0) q.push(i);
		}

		int num_sem = 0, num_taken = q.size();
		while (!q.empty()) {
			int q_size = q.size();
			num_sem++;
			for (int i = 0; i < q_size; ++i) {
				int x = q.front();
				q.pop();
				for (int j = 0; j < rel[x].size(); ++j) {
					int y = rel[x][j];
					if (--courses[y] == 0) {
						q.push(y);
						num_taken++;
					}
				}
			}
		}
		return num_taken == N ? num_sem : -1;
	}
};

int main() {
	vector<vector<int> > relations;
	int r1[] = {1, 2};
	int r2[] = {2, 3};
	int r3[] = {3, 1};
	relations.push_back(vector<int>(r1, r1 + 2));
	relations.push_back(vector<int>(r2, r2 + 2));
	relations.push_back(vector<int>(r3, r3 + 2));

	int N = 3;

	Solution sol;
	cout << sol.minimumSemesters(N, relations) << endl;
}