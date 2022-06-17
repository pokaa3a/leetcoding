#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution
{
public:
    // Time: O(n * n * fuel)
    // Space: O(n * fuel)
    int countRoutes(vector<int> &locations, int start, int finish, int fuel)
    {
        dp = vector<vector<long long> >(locations.size(), vector<long long>(fuel + 1, -1));
        return countRoutesImpl(locations, start, finish, fuel);
    }

    long long countRoutesImpl(vector<int> &locations, int start, int finish, int fuel)
    {
        if (dp[start][fuel] != -1)
        {
            return dp[start][fuel];
        }

        long long count = 0;
        if (start == finish)
            count++;

        for (int i = 0; i < locations.size(); ++i)
        {
            if (i == start)
                continue;

            long long cost = abs(locations[i] - locations[start]);
            if (cost <= fuel)
            {
                count = (count + countRoutesImpl(locations, i, finish, fuel - cost)) % 1000000007;
            }
        }

        dp[start][fuel] = count;
        return count;
    }

private:
    vector<vector<long long> > dp;
};

int main()
{
    Solution sol;
    {
        vector<int> locations = {2, 3, 6, 8, 4};
        int start = 1;
        int finish = 3;
        int fuel = 5;
        cout << sol.countRoutes(locations, start, finish, fuel) << endl;
    }

    {
        vector<int> locations = {4, 3, 1};
        int start = 1;
        int finish = 0;
        int fuel = 6;
        cout << sol.countRoutes(locations, start, finish, fuel) << endl;
    }

    {
        vector<int> locations = {5, 2, 1};
        int start = 0;
        int finish = 2;
        int fuel = 3;
        cout << sol.countRoutes(locations, start, finish, fuel) << endl;
    }

    {
        vector<int> locations = {2, 1, 5};
        int start = 0;
        int finish = 0;
        int fuel = 3;
        cout << sol.countRoutes(locations, start, finish, fuel) << endl;
    }
}