#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
	int minAreaRect(vector<vector<int> >& points) {
		unordered_map<int, unordered_set<int> > pts_map;
		for (int i = 0; i < points.size(); ++i) {
			pts_map[points[i][0]].insert(points[i][1]);
		}

		int ans = INT_MAX;
		for (int i = 0; i < points.size(); ++i) {
			int x0 = points[i][0];
			int y0 = points[i][1];
			if (pts_map[x0].size() < 2) continue;
			for (int j = i + 1; j < points.size(); ++j) {
				int x1 = points[j][0];
				int y1 = points[j][1];
				if (pts_map[x1].size() < 2) continue;
				if (x1 == x0 || y1 == y0) continue;
				if (pts_map[x0].count(y1) && pts_map[x1].count(y0)) {
					int area = abs(x1 - x0) * abs(y1 - y0);
					ans = min(ans, area);
				}
			}
		}
		return ans == INT_MAX ? 0 : ans;
	}
};

int main() {
	int pts0[] = {1, 1};
	int pts1[] = {1, 3};
	int pts2[] = {3, 1};
	int pts3[] = {3, 3};
	int pts4[] = {2, 2};

	vector<vector<int> > points;
	points.push_back(vector<int>(pts0, pts0 + 2));
	points.push_back(vector<int>(pts1, pts1 + 2));
	points.push_back(vector<int>(pts2, pts2 + 2));
	points.push_back(vector<int>(pts3, pts3 + 2));
	points.push_back(vector<int>(pts4, pts4 + 2));

	Solution sol;
	cout << sol.minAreaRect(points) << endl;

}