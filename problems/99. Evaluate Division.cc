#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <set>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
	vector<double> calcEquation(vector<pair<string, string> > equations, 
								vector<double> &values,
								vector<pair<string, string> > queries) {
		unordered_map<string, vector<pair<string, double> > > graph;
		for (int i = 0; i < equations.size(); ++i) {
			string n = equations[i].first;
			string d = equations[i].second;
			double v = values[i];
			graph[n].push_back(make_pair(d, v));
			graph[d].push_back(make_pair(n, 1.0 / v));
		}
		vector<double> ans;
		for (int i = 0; i < queries.size(); ++i) {
			string n = queries[i].first;
			string d = queries[i].second;
			if (graph.count(n) == 0 || graph.count(d) == 0) ans.push_back(-1);
			else if (n == d) ans.push_back(1);
			else {
				set<string> visited;
				queue<pair<string, double> > q;
				q.push(make_pair(n, 1));
				visited.insert(n);
				while (!q.empty()) {
					pair<string, double> next = q.front();
					for (int j = 0; j < graph[next.first].size(); ++j) {
						double quotient = next.second;
						pair<string, double> v = graph[next.first][j];
						if (visited.count(v.first)) continue;
						visited.insert(v.first);
						quotient *= v.second;
						q.push(make_pair(v.first, quotient));
						if (v.first == d) {
							ans.push_back(quotient);
							break;
						}
					}
					q.pop();
				}
				if (!visited.count(d)) ans.push_back(-1);
			}
		}
		return ans;
	}
};

int main() {
	// equations
	vector<pair<string, string> > equations;
	equations.push_back(make_pair("a", "b"));
	equations.push_back(make_pair("b", "c"));
	equations.push_back(make_pair("bc", "cd"));
	// values
	vector<double> values;
	values.push_back(1.5);
	values.push_back(2.5);
	values.push_back(5.0);
	// queries
	vector<pair<string, string> > queries;
	queries.push_back(make_pair("a", "c"));
	queries.push_back(make_pair("c", "b"));
	queries.push_back(make_pair("bc", "cd"));
	queries.push_back(make_pair("cd", "bc"));

	Solution sol;
	vector<double> ans = sol.calcEquation(equations, values, queries);
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << " ";
	}
	cout << endl;
}