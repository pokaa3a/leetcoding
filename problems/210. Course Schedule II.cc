#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int> > &prerequisites)
    {
        unordered_map<int, vector<int> > graph;
        for (auto pre : prerequisites)
        {
            graph[pre[0]].push_back(pre[1]);
        }
        vector<int> status(numCourses, 0); // 0: not visited, 1: visited, 2: added
        vector<int> res;
        for (int i = 0; i < numCourses; i++)
        {
            if (!tp_sort(i, graph, status, res))
                return vector<int>();
        }
        return res;
    }
    bool tp_sort(int course, unordered_map<int, vector<int> > &graph, vector<int> &status, vector<int> &res)
    {
        if (status[course] == 2)
            return true;
        if (status[course] == 1)
            return false;
        status[course] = 1;
        for (auto next : graph[course])
        {
            if (!tp_sort(next, graph, status, res))
                return false;
        }
        status[course] = 2;
        res.push_back(course);
        return true;
    }
};