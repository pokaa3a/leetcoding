#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

class Solution {
public:
	vector<int> findMinHeightTrees(int n, vector<pair<int, int> >& edges) {
		if (n == 1) {
			return vector<int>(1, 0);
		}
		vector<vector<int> > graph(n, vector<int>());
		vector<int> degree(n, 0);
		for (int i = 0; i < edges.size(); ++i) {
			int x = edges[i].first;
			int y = edges[i].second;
			graph[x].push_back(y);
			graph[y].push_back(x);
			degree[x]++;
			degree[y]++;
		}
		queue<int> q;
		for (int i = 0; i < n; ++i) {
			if (degree[i] == 1) q.push(i);
		}
		vector<int> ans;
		while (!q.empty()) {
			ans.clear();
			int q_length = q.size();
			for (int i = 0; i < q_length; ++i) {
				int n = q.front();
				q.pop();
				degree[n]--;
				ans.push_back(n);
				for (int j = 0; j < graph[n].size(); ++j) {
					int m = graph[n][j];
					if (degree[m] == 0) continue;
					else if (degree[m] == 2) q.push(m);
					degree[m]--;
				}
			}
		}
		return ans;
	}
};

int main() {
	int n = 6;
	vector<pair<int, int> > edges;
	edges.push_back(make_pair(0, 3));
	edges.push_back(make_pair(1, 3));
	edges.push_back(make_pair(2, 3));
	edges.push_back(make_pair(4, 3));
	edges.push_back(make_pair(5, 4));
	Solution sol;
	vector<int> MHT = sol.findMinHeightTrees(n, edges);
	for (int i = 0; i < MHT.size(); ++i) {
		cout << MHT[i] << " ";
	}
	cout << endl;
}