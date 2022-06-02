#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    // DP: Kadane's algorithm
    int largestVariance(string s)
    {
        // Complexity: O(26*26*N)

        int ans = 0;
        for (char h = 'a'; h <= 'z'; ++h)
        {
            for (char l = 'a'; l <= 'z'; ++l)
            {
                if (h == l)
                    continue;

                // h: char with higher freq
                // l: char with lower freq
                int hFreq = 0;
                int lFreq = 0;

                bool hasLower = false;

                for (auto c : s)
                {
                    if (c == h)
                        hFreq++;
                    else if (c == l)
                        lFreq++;

                    if (lFreq > 0)
                    {
                        ans = max(ans, hFreq - lFreq);
                    }
                    else if (lFreq == 0 && hasLower)
                    {
                        ans = max(ans, hFreq - 1);
                    }

                    if (lFreq > hFreq)
                    {
                        hFreq = 0;
                        lFreq = 0;
                        hasLower = true;
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    {
        string s = "babbb";
        cout << sol.largestVariance(s) << endl;
    }

    {
        string s = "abcde";
        cout << sol.largestVariance(s) << endl;
    }

    {
        string s = "aaaa";
        cout << sol.largestVariance(s) << endl;
    }
}