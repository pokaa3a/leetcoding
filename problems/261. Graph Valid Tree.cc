#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

// class Solution {
// public:
// 	bool validTree(int n, vector<vector<int> >& edges) {
// 		vector<set<int> > graph(n, set<int>());
// 		for (int i = 0; i < edges.size(); ++i) {
// 			graph[edges[i][0]].insert(edges[i][1]);
// 			graph[edges[i][1]].insert(edges[i][0]);
// 		}
// 		queue<int> q;
// 		set<int> visited;

// 		q.push(0);
// 		visited.insert(0);
// 		while (!q.empty()) {
// 			int q_size = q.size();
// 			for (int i = 0; i < q_size; ++i) {
// 				int cur = q.front();
// 				cout << "cur: " << cur << endl;
// 				q.pop();
// 				for (set<int>::iterator it = graph[cur].begin(); it != graph[cur].end(); ++it) {
// 					if (visited.find(*it) != visited.end()) return false;
// 					cout << "edge to: " << *it << endl;
// 					q.push(*it);
// 					visited.insert(*it);
// 					graph[*it].erase(cur);
// 				}
// 			}
// 		}
// 		return visited.size() == n ? true : false;
// 	}
// };

class Solution {
public:
	bool validTree(int n, vector<vector<int> >& edges) {
		vector<vector<int> > graph(n, vector<int>());
		for (int i = 0; i < edges.size(); ++i) {
			graph[edges[i][0]].push_back(edges[i][1]);
			graph[edges[i][1]].push_back(edges[i][0]);
		}

		vector<int> visited(n, -1);		// -1: not visited, 0: in visit, 1: visited
		if (!dfs(graph, visited, 0, -1)) return false;

		int sum = 0;
		for (int i = 0; i < visited.size(); ++i) {
			sum += visited[i];
		}
		return sum == n ? true : false;
	}
private:
	bool dfs(vector<vector<int> >& graph, vector<int>& visited, int start, int parent) {
		if (visited[start] >= 0) return visited[start];

		visited[start] = 0;
		for (int i = 0; i < graph[start].size(); ++i) {
			int n = graph[start][i];
			if (n == parent) continue;
			if (!dfs(graph, visited, n, start)) return 0;
		}
		visited[start] = 1;
		return 1;
	}
};


int main() {
	int n = 5;
	vector<vector<int> > edges;
	int e1[] = {0, 1};
	int e2[] = {1, 2};
	int e3[] = {2, 3};
	int e4[] = {1, 3};
	int e5[] = {1, 4};
	edges.push_back(vector<int>(e1, e1 + 2));
	edges.push_back(vector<int>(e2, e2 + 2));
	edges.push_back(vector<int>(e3, e3 + 2));
	edges.push_back(vector<int>(e4, e4 + 2));
	edges.push_back(vector<int>(e5, e5 + 2));

	Solution sol;
	cout << sol.validTree(n, edges) << endl;
}