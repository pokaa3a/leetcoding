#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int getMaxLen(vector<int> &nums)
    {
        int ans = 0;
        int longestNeg = 0;
        int longestPos = 0;

        for (int x : nums)
        {
            int tmpPos = longestPos;
            int tmpNeg = longestNeg;

            if (x > 0)
            {
                longestPos++;
                if (tmpNeg > 0)
                    longestNeg++;
            }
            else if (x < 0)
            {
                if (tmpNeg > 0)
                    longestPos = tmpNeg + 1;
                else
                    longestPos = 0;
                longestNeg = tmpPos + 1;
            }
            else // x == 0
            {
                longestPos = 0;
                longestNeg = 0;
            }

            // cout << "x: " << x << endl;
            // cout << "  Pos: " << longestPos << " Neg: " << longestNeg << endl;

            ans = max(ans, longestPos);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    {
        vector<int> nums = {1, -2, -3, 4};
        cout << sol.getMaxLen(nums) << endl;
    }

    {
        vector<int> nums = {0, 1, -2, -3, -4};
        cout << sol.getMaxLen(nums) << endl;
    }

    {
        vector<int> nums = {-1, -2, -3, 0, 1};
        cout << sol.getMaxLen(nums) << endl;
    }
}