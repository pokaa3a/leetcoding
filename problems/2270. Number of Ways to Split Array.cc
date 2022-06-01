#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int waysToSplitArray(vector<int> &nums)
    {
        long long sum = 0;
        int ans = 0;

        vector<long long> presum(nums.size());

        for (int i = 0; i < nums.size(); ++i)
        {
            presum[i] = (i == 0 ? 0 : presum[i - 1]) + nums[i];
            sum += nums[i];
        }

        for (int i = 0; i < nums.size() - 1; ++i)
        {
            auto leftSum = presum[i];
            auto rightSum = sum - leftSum;
            if (leftSum >= rightSum)
            {
                ans++;
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> vec1 = {10, 4, -8, 7};
    vector<int> vec2 = {2, 3, 1, 0};

    Solution sol;
    cout << sol.waysToSplitArray(vec1) << endl;
    cout << sol.waysToSplitArray(vec2) << endl;
}