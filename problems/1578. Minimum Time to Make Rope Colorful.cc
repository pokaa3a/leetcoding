#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    // Time: O(n)
    // Space: O(1)
    int minCost(string colors, vector<int> &neededTime)
    {
        int cost = 0;
        for (int i = 0; i < colors.size();)
        {
            i = remove(cost, i, colors, neededTime);
        }
        return cost;
    }
    int remove(int &cost, int start, const string &colors, const vector<int> &neededTime)
    {
        int total = 0;
        int biggestCost = 0;

        int i = 0;
        for (; i + start < colors.size() && colors[i + start] == colors[start]; ++i)
        {
            total += neededTime[i + start];
            biggestCost = max(biggestCost, neededTime[i + start]);
        }

        if (i > 1)
        {
            cost += total - biggestCost;
        }

        return i + start;
    }
};

int main()
{
    Solution sol;
    {
        string colors = "abaac";
        vector<int> neededTime = {1, 2, 3, 4, 5};
        cout << sol.minCost(colors, neededTime) << endl;
    }

    {
        string colors = "abc";
        vector<int> neededTime = {1, 2, 3};
        cout << sol.minCost(colors, neededTime) << endl;
    }

    {
        string colors = "aabaa";
        vector<int> neededTime = {1, 2, 3, 4, 1};
        cout << sol.minCost(colors, neededTime) << endl;
    }

    {
        string colors = "bbbaaa";
        vector<int> neededTime = {4, 9, 3, 8, 8, 9};
        cout << sol.minCost(colors, neededTime) << endl;
    }
}