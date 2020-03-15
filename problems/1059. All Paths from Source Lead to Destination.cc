#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int> >& edges, int source, int destination) {
        // build graph
        vector<vector<int> > graph(n, vector<int>());
        for (int i = 0; i < edges.size(); ++i) {
        	int u = edges[i][0];
        	int v = edges[i][1];
        	graph[u].push_back(v);
        }

        vector<bool> visited(n, false);
        visited[source] = true;
        if (helper(source, destination, graph, visited)) return true;
        return false;
    }

    bool helper(int src, int dst, vector<vector<int> >& graph, vector<bool>& visited) {
    	if (graph[src].size() == 0) {
    		if (src == dst) return true;
    		else return false;
    	}

    	for (int i = 0; i < graph[src].size(); ++i) {
    		int v = graph[src][i];
    		if (visited[v]) return false;
    		visited[v] = true;
    		if (!helper(v, dst, graph, visited)) return false;
    		visited[v] = false;
    	}
    	return true;
    }
};

int main() {
	int n = 2;
	int e1[] = {0, 1};
	int e2[] = {1, 1};
	// int e3[] = {1, 2};
	// int e4[] = {2, 3};
	vector<vector<int> > edges;
	edges.push_back(vector<int>(e1, e1 + 2));
	edges.push_back(vector<int>(e2, e2 + 2));
	// edges.push_back(vector<int>(e3, e3 + 2));
	// edges.push_back(vector<int>(e4, e4 + 2));
	int source = 0;
	int destination = 1;
	Solution sol;
	cout << sol.leadsToDestination(n, edges, source, destination) << endl;
}