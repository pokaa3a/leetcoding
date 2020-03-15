#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> assignBikes(vector<vector<int> >& workers, 
							vector<vector<int> >& bikes) {
		vector<vector<pair<int, int> > > buckets(2000);
		for (int i = 0; i < workers.size(); ++i) {
			for (int j = 0; j < bikes.size(); ++j) {
				int dist = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
				buckets[dist].push_back(make_pair(i, j));
			}
		}
		vector<int> ans(workers.size(), -1);
		vector<bool> used_bike(bikes.size(), false);
		for (int d = 0; d < 2000; ++d) {
			for (int k = 0; k < buckets[d].size(); ++k) {
				int worker_id = buckets[d][k].first;
				int bike_id = buckets[d][k].second;
				if (ans[worker_id] == -1 && !used_bike[bike_id]) {
					ans[worker_id] = bike_id;
					used_bike[bike_id] = true;
				}
			}
		}
		return ans;
	}
};

int main() {
	vector<vector<int> > workers;
	vector<vector<int> > bikes;

	int worker0[] = {0, 0};
	int worker1[] = {2, 1};
	// int worker2[] = {2, 0};
	int bike0[] = {1, 2};
	int bike1[] = {3, 3};
	// int bike2[] = {2, 1};

	workers.push_back(vector<int>(worker0, worker0 + 2));
	workers.push_back(vector<int>(worker1, worker1 + 2));
	// workers.push_back(vector<int>(worker2, worker2 + 2));
	bikes.push_back(vector<int>(bike0, bike0 + 2));
	bikes.push_back(vector<int>(bike1, bike1 + 2));
	// bikes.push_back(vector<int>(bike2, bike2 + 2));
	Solution sol;
	vector<int> ans = sol.assignBikes(workers, bikes);
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << " ";
	}
	cout << endl;
}