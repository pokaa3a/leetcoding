#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

#define MOD 1000000007

class Solution
{
public:
    int numWays(string s)
    {
        unordered_map<int, int> mp; // {1s count, index}

        int total = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '1')
            {
                total++;
                mp.insert({total, i});
            }
        }

        if (total % 3 != 0)
            return 0;

        if (total == 0)
        {
            long long len = s.size() - 1;
            return (len * (len - 1) / 2) % MOD;
        }

        int idx1 = mp[total / 3];
        int idx2 = mp[total / 3 + 1];
        long long len1 = idx2 - idx1;

        int idx3 = mp[total / 3 * 2];
        int idx4 = mp[total / 3 * 2 + 1];
        long long len2 = idx4 - idx3;

        return len1 * len2 % MOD;
    }
};

int main()
{
    Solution sol;
    {
        string s = "10101";
        cout << sol.numWays(s) << endl;
    }

    {
        string s = "1001";
        cout << sol.numWays(s) << endl;
    }

    {
        string s = "0000";
        cout << sol.numWays(s) << endl;
    }
}