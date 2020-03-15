#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	int findMinArrowShots(vector<vector<int> > &points) {
		if (points.size() == 0) return 0;

		vector<pair<int, int> > balloons;
		for (int i = 0; i < points.size(); ++i) {
			balloons.push_back(make_pair(points[i][0], points[i][1]));
		}
		sort(balloons.begin(), balloons.end());

		int ans = 1;
		int last = balloons[0].second;
		for (int i = 0; i < balloons.size(); ++i) {
			if (balloons[i].first <= last) {
				last = min(last, balloons[i].second);
			} else {
				last = balloons[i].second;
				ans++;
			}
		}
		return ans;
	}
};

int main() {
	int balloon0[] = {9, 12};
	int balloon1[] = {1, 10};
	int balloon2[] = {4, 11};
	int balloon3[] = {8, 12};
	int balloon4[] = {3, 9};
	int balloon5[] = {6, 9};
	int balloon6[] = {6, 7};


	vector<vector<int> > points;
	points.push_back(vector<int>(balloon0, balloon0 + 2));
	points.push_back(vector<int>(balloon1, balloon1 + 2));
	points.push_back(vector<int>(balloon2, balloon2 + 2));
	points.push_back(vector<int>(balloon3, balloon3 + 2));
	points.push_back(vector<int>(balloon4, balloon4 + 2));
	points.push_back(vector<int>(balloon5, balloon5 + 2));
	points.push_back(vector<int>(balloon6, balloon6 + 2));
	// points.push_back(vector<int>(balloon7, balloon7 + 2));
	// points.push_back(vector<int>(balloon8, balloon8 + 2));
	// points.push_back(vector<int>(balloon9, balloon9 + 2));

	Solution sol;
	cout << sol.findMinArrowShots(points) << endl;
}