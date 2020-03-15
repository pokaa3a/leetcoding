#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int> >& red_edges, 
    											vector<vector<int> >& blue_edges) {
        red_count.resize(n, -1);
        blue_count.resize(n, -1);

        for (int i = 0; i < red_edges.size(); ++i) {
        	red_graph[red_edges[i][0]].push_back(red_edges[i][1]);
        }
        for (int i = 0; i < blue_edges.size(); ++i) {
        	blue_graph[blue_edges[i][0]].push_back(blue_edges[i][1]);
        }

        dfs(0, 0, true);
        dfs(0, 0, false);

        vector<int> res(n, -1);
        for (int i = 0; i < n; ++i) {
        	int r = red_count[i];
        	int b = blue_count[i];
        	if (r == -1) res[i] = b;
        	else if (b == -1) res[i] = r;
        	else res[i] = min(r, b);
        }
        return res;
    }
private:
	vector<int> red_count;
	vector<int> blue_count;
	map<int, vector<int> > red_graph;
	map<int, vector<int> > blue_graph;
	void dfs(int node_id, int dist, bool is_red) {
		if (is_red) {
			if (red_count[node_id] == -1) red_count[node_id] = dist;
			else {
				if (red_count[node_id] < dist) return;
				else red_count[node_id] = dist;
			}

			for (int i = 0; i < red_graph[node_id].size(); ++i) {
				dfs(red_graph[node_id][i], dist + 1, !is_red);
			}
		} else {
			if (blue_count[node_id] == -1) blue_count[node_id] = dist;
			else {
				if (blue_count[node_id] < dist) return;
				else blue_count[node_id] = dist;
			}

			for (int i = 0; i < blue_graph[node_id].size(); ++i) {
				dfs(blue_graph[node_id][i], dist + 1, !is_red);
			}
		}
	}
};

int main() {
	int n = 5;
	int r1[] = {0, 1};
	int r2[] = {1, 2};
	int r3[] = {2, 3};
	int r4[] = {3, 4};


	int b1[] = {1, 2};
	int b2[] = {2, 3};
	int b3[] = {3, 1};
	vector<vector<int> > red_edges;
	red_edges.push_back(vector<int>(r1, r1 + 2));
	red_edges.push_back(vector<int>(r2, r2 + 2));
	red_edges.push_back(vector<int>(r3, r3 + 2));
	red_edges.push_back(vector<int>(r4, r4 + 2));

	vector<vector<int> > blue_edges;
	blue_edges.push_back(vector<int>(b1, b1 + 2));
	blue_edges.push_back(vector<int>(b2, b2 + 2));
	blue_edges.push_back(vector<int>(b3, b3 + 2));

	Solution sol;
	vector<int> res = sol.shortestAlternatingPaths(n, red_edges, blue_edges);
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << " ";
	}
	cout << endl;
}