#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
	// BFS
	bool isBipartite(vector<vector<int> > &graph) {
		vector<int> group(graph.size(), 0);
		for (int i = 0; i < graph.size(); ++i) {
			if (group[i] != 0) continue;
			group[i] = 1;
			queue<int> q;
			q.push(i);
			while (!q.empty()) {
				int front = q.front();
				q.pop();
				for (int j = 0; j < graph[front].size(); ++j) {
					int e = graph[front][j];
					if (group[e] == 0) {
						group[e] = -group[front];
						q.push(e);
					}
					else if (group[e] == group[front]) return false;
				}
			}
		}
		return true;
	}
};

int main() {
	vector<vector<int> > graph;
	int edge0[] = {1, 3};
	graph.push_back(vector<int>(edge0, edge0 + 2));
	int edge1[] = {0, 2};
	graph.push_back(vector<int>(edge1, edge1 + 2));
	int edge2[] = {1, 3};
	graph.push_back(vector<int>(edge2, edge2 + 2));
	int edge3[] = {0, 2};
	graph.push_back(vector<int>(edge3, edge3 + 2));

	Solution sol;
	cout << sol.isBipartite(graph) << endl;
}