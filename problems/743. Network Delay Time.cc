#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

struct comp {
	bool operator() (const pair<int, int>& a, const pair<int, int>& b) {
		return a.second > b.second;
	}
};

class Solution {
public:
	int networkDelayTime(vector<vector<int> > &times, int N, int K) {
		// build graph
		vector<vector<pair<int, int> > > net(N);
		for (int i = 0; i < times.size(); ++i) {
			int src = times[i][0] - 1;
			int dst = times[i][1] - 1;
			int t = times[i][2];
			net[src].push_back(make_pair(dst, t));
		}

		vector<int> dist(N, INT_MAX);
		unordered_set<int> visted;
		int longest = 0;
		priority_queue<pair<int, int>, vector<pair<int, int> >, comp> q;
		q.push(make_pair(K - 1, 0));
		dist[K - 1] = 0;

		while (!q.empty()) {
			int src = q.top().first;
			int time = q.top().second;
			visted.insert(src);
			longest = max(longest, dist[src]);

			cout << "shortest: " << src + 1 << ": " << time << endl;

			q.pop();
			for (int i = 0; i < net[src].size(); ++i) {
				int dst = net[src][i].first;
				int t = net[src][i].second;
				if (visted.find(dst) == visted.end() && time + t < dist[dst]) {
					cout << "add " << dst + 1 << " with time " << time + t << endl;
					q.push(make_pair(dst, time + t));
					dist[dst] = time + t;
				}
			}
		}
		return visted.size() == N ? longest : -1;
	}
};

int main () {
	int t0[] = {1, 2, 1};
	int t1[] = {2, 3, 2};
	int t2[] = {1, 3, 2};
	int N = 3, K = 1;

	vector<vector<int> > times;
	times.push_back(vector<int>(t0, t0 + 3));
	times.push_back(vector<int>(t1, t1 + 3));
	times.push_back(vector<int>(t2, t2 + 3));

	Solution sol;
	cout << sol.networkDelayTime(times, N, K) << endl;
}