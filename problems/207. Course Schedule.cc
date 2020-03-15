#include <iostream>
#include <vector>
#include <pair>
#include <set>
using namespace std;

// BFS-1
class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
		vector<set<int> > graph = make_graph(numCourses, prerequisites);
		vector<int> indegrees = get_indegree(graph);

		for (int i = 0; i < numCourses; ++i) {
			int j = 0;
			while (j < numCourses) {
				if (indegrees[j] == 0) break;
				j++;
			}
			if (j == numCourses) return false;
			indegrees[j] = -1;
			for (auto node : graph[j]) {
				indegrees[node]--;
			}
		}
		return true;
	}

private:
	vector<set<int> > make_graph(int numCourses, vector<pair<int, int> >& prerequisites) {
		vector<set<int> > graph(numCourses);
		for (auto pre : prerequisites) {
			graph[pre.second].insert(pre.first);
		}
		return graph;
	}

	vector<int> get_indegree(vector<set<int> >& graph) {
		vector<int> indegrees(graph.size(), 0);
		for (auto course : graph) {
			for (auto following_course : course) {
				indegrees[following_course]++;
			}
		}
		return indegrees;
	}
};

// BFS-2
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph = makeGraph(numCourses, prerequisites);
        vector<int> indegrees = getIndegrees(graph);
        queue<int> zero_indegree;
        for (int i = 0; i < numCourses; ++i) {
            if (indegrees[i] == 0) zero_indegree.push(i);
        }
        
        int count = 0;
        while (!zero_indegree.empty()) {
            int n = zero_indegree.front();
            zero_indegree.pop();
            count++;
            for (auto m : graph[n]) {
                if (--indegrees[m] == 0) {
                    zero_indegree.push(m);
                }
            }
        }
        return count == numCourses;
    }
private:
    vector<vector<int>> makeGraph(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (auto edge : prerequisites) {
            graph[edge.second].push_back(edge.first);
        }
        return graph;
    }
    
    vector<int> getIndegrees(vector<vector<int>>& graph) {
        vector<int> indegrees(graph.size(), 0);
        for (auto nodes : graph) {
            for (auto node : nodes) {
                indegrees[node]++;
            }
        }
        return indegrees;
    }
};

// DFS
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph = makeGraph(numCourses, prerequisites);
        vector<int> mark(numCourses, 0); // 0: unmarked, 1: temp mark, 2: permermant mark
    
        for (int i = 0; i < numCourses; ++i) {
            if (!visit(i, graph, mark)) return false;
        }
        return true;
    }
private:
    vector<vector<int>> makeGraph(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (auto edge : prerequisites) {
            graph[edge.second].push_back(edge.first);
        }
        return graph;
    }
    
    bool visit(int node, vector<vector<int>>& graph, vector<int>& mark) {
        if (mark[node] == 2) return true;
        if (mark[node] == 1) return false;
        mark[node] = 1;
        for (auto m : graph[node]) {
            if (!visit(m, graph, mark)) return false;
        }
        mark[node] = 2;
        return true;
    }
};