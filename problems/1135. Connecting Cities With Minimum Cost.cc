#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int minimumCost(int N, vector<vector<int> >& connections) {
		group.resize(N + 1, 0);
		for (int i = 1; i < N + 1; ++i) group[i] = i;
		for (int i = 0; i < connections.size(); ++i) swap(connections[i][0], connections[i][2]);
		sort(connections.begin(), connections.end());

		int num_edges = 0;
		int cost = 0;
		for (int i = 0; num_edges < N - 1 && i < connections.size(); ++i) {
			int x = find(connections[i][1]);
			int y = find(connections[i][2]);
			// cout << "x: " << x << " y: " << y << endl;
			// cout << "cost: " << connections[i][0] << endl;
			if (x != y) {
				cost += connections[i][0];
				num_edges++;
				group[x] = y;
			}
		}
		return num_edges == N - 1 ? cost : -1;
	}
private:
	vector<int> group;
	int find(int x) {
		if (x != group[x]) group[x] = find(group[x]);
		return group[x];
	}
};

int main() {
	int N = 4;
	vector<vector<int> > connections;
	int e1[] = {1, 2, 3};
	int e2[] = {3, 4, 4};
	// int e3[] = {2, 3, 1};
	connections.push_back(vector<int>(e1, e1 + 3));
	connections.push_back(vector<int>(e2, e2 + 3));
	// connections.push_back(vector<int>(e3, e3 + 3));
	Solution sol;
	cout << sol.minimumCost(N, connections) << endl;

}