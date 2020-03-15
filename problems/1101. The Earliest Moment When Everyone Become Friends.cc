#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	int earliestAcq(vector<vector<int> >& logs, int N) {
		group.resize(N, 0);
		map<int, int> group_count;

		for (int i = 0; i < N; ++i) {
			group[i] = i;
			group_count[i] = 1;
		}

		sort(logs.begin(), logs.end());
		for (int i = 0; i < logs.size(); ++i) {
			int t = logs[i][0];
			int p1 = logs[i][1];
			int p2 = logs[i][2];
			// cout << "t: " << t << " " << p1 << ", " << p2 << endl;

			int x = find(p1), y = find(p2);
			if (x != y) {
				group[x] = y;
				group_count[y] += group_count[x];
				group_count[x] = 0;
				if (group_count[y] >= N) return t;
			}
			// for (map<int, int>::iterator it = group_count.begin(); it != group_count.end(); ++it) {
			// 	cout << it->second << " ";
			// }
			// cout << endl;
		}
		return -1;
	}
private:
	vector<int> group;
	int find(int x) {
		if (x != group[x]) group[x] = find(group[x]);
		return group[x];
	}
};

int main() {
	int log_arr[8][3] = {{20190101,0,1}, {20190104,3,4}, {20190107,2,3}, {20190211,1,5},
				   	     {20190224,2,4}, {20190301,0,3}, {20190312,1,2}, {20190322,4,5}};
	vector<vector<int> > logs;

	for (int i = 0; i < 8; ++i) {
		logs.push_back(vector<int>(log_arr[i], log_arr[i] + 3));
	}
	int N = 6;

	Solution sol;
	cout << sol.earliestAcq(logs, N) << endl;
}