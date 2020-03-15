#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
class Solution {
public:
	vector<int> findRedundantConnection(vector<vector<int> > &edges) {
		int n = edges.size();
		vector<int> parents(n + 1, 0);
		for (int i = 0; i < n; ++i) {
			parents[i] = i;
		}
		for (int i = 0; i < n; ++i) {
			int x = edges[i][0];
			int y = edges[i][1];
			int x_parents = findParents(parents, x);
			int y_parents = findParents(parents, y);
			if (x_parents == y_parents) return edges[i];
			parents[x_parents] = y_parents;
		}
		return vector<int>();
	}
	int findParents(vector<int> &parents, int x) {
		if (x != parents[x]) parents[x] = findParents(parents, parents[x]);
		return parents[x];
	}
};

int main() {
	vector<vector<int> > edges;
	int e1[] = {1, 2};
	edges.push_back(vector<int>(e1, e1 + 2));
	int e2[] = {1, 3};
	edges.push_back(vector<int>(e2, e2 + 2));
	int e3[] = {2, 3};
	edges.push_back(vector<int>(e3, e3 + 2));
	// int e4[] = {3, 5};
	// edges.push_back(vector<int>(e4, e4 + 2));
	// int e5[] = {2, 5};
	// edges.push_back(vector<int>(e5, e5 + 2));
	Solution sol;
	vector<int> ans = sol.findRedundantConnection(edges);
	cout << ans[0] << ", " << ans[1] << endl;
}