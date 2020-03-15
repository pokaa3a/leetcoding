#include <iostream>
#include <vector>
#include <pair>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph = makeGraph(numCourses, prerequisites);
        vector<int> inorders = computeInOrders(graph);

        queue<int> zero_inorder;
        vector<int> order;
        
        for (int i = 0; i < numCourses; ++i) {
            if (inorders[i] == 0)
                zero_inorder.push(i);
        }
        int count = 0;
        while (!zero_inorder.empty()) {
            int n = zero_inorder.front();
            zero_inorder.pop();
            order.push_back(n);
            count++;
            for (auto m : graph[n]) {
                if (--inorders[m] == 0) {
                    zero_inorder.push(m);
                }
            }
        }
        return (count != numCourses ? vector<int>() : order);
    }
private:
    vector<vector<int>> makeGraph(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for (auto edge : prerequisites) {
            graph[edge.second].push_back(edge.first);
        }
        return graph;
    }
    vector<int> computeInOrders(vector<vector<int>> graph) {
        vector<int> inorders(graph.size(), 0);
        for (auto nodes : graph) {
            for (auto node : nodes) {
                inorders[node]++;
            }
        }
        return inorders;
    }
};