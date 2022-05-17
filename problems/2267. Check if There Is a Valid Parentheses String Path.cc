#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool hasValidPath(vector<vector<char> > &grid)
    {
        size_t m = grid.size();
        size_t n = grid[0].size();

        if ((m + n - 1) % 2 != 0)
            return false;
        const int limit = (m + n - 1) / 2;

        vector<vector<unordered_set<int> > > dp(m, vector<unordered_set<int> >(n));

        for (int r = 0; r < m; ++r)
        {
            for (int c = 0; c < n; ++c)
            {
                int add = grid[r][c] == '(' ? 1 : -1;

                if (r == 0 && c == 0)
                {
                    if (add > 0)
                    {
                        dp[r][c].insert(add);
                    }
                    continue;
                }

                // From top
                if (r > 0)
                {
                    for (const auto x : dp[r - 1][c])
                    {
                        if (x + add <= limit && x + add >= 0)
                        {
                            dp[r][c].insert(x + add);
                        }
                    }
                }

                // From left
                if (c > 0)
                {
                    for (const auto x : dp[r][c - 1])
                    {
                        if (x + add <= limit && x + add >= 0)
                        {
                            dp[r][c].insert(x + add);
                        }
                    }
                }
            }
        }
        return dp[m - 1][n - 1].count(0) > 0;
    }
};

int main()
{
    Solution sol;

    // TEST1
    {
        vector<vector<char> > grid = {{'(', '(', '('},
                                      {')', '(', ')'},
                                      {'(', '(', ')'},
                                      {'(', '(', ')'}};
        cout << sol.hasValidPath(grid) << endl;
    }

    // TEST2
    {
        vector<vector<char> > grid = {{')', ')'}, {'(', '('}};
        cout << sol.hasValidPath(grid) << endl;
    }

    // TEST3
    {
        vector<vector<char> > grid = {{')', '('}};
        cout << sol.hasValidPath(grid) << endl;
    }
}