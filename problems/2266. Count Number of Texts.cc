#include <iostream>
#include <vector>
using namespace std;

#define MOD 1000000007
#define EXPECT_EQ(x, y) \
    std::cout << "Ans: " << x << ", Expect: " << y << std::endl;

class Solution
{
public:
    int countTexts(string pressedKeys)
    {
        // DP
        vector<long long> dp(pressedKeys.size());

        for (int i = 0; i < pressedKeys.size(); ++i)
        {
            long long val = 0;

            int maxPresses = 3;
            if (pressedKeys[i] == '7' || pressedKeys[i] == '9')
            {
                maxPresses = 4;
            }

            for (int j = 0; j < maxPresses; ++j)
            {
                char c = pressedKeys[i];
                if (i - j >= 0 && pressedKeys[i - j] == c)
                {
                    val = (val + (i - j > 0 ? dp[i - j - 1] : 1)) % MOD;
                }
                else
                {
                    break;
                }
            }
            dp[i] = val;
        }
        return dp.back();
    }
};

int main()
{
    Solution sol;

    // TEST1
    {
        string pressedKeys = "22233";
        EXPECT_EQ(sol.countTexts(pressedKeys), 8);
    }

    // TEST2
    {
        string pressedKeys = "222222222222222222222222222222222222";
        EXPECT_EQ(sol.countTexts(pressedKeys), 82876089);
    }
}