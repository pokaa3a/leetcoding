#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findLengthOfShortestSubarray(vector<int> &arr)
    {
        if (arr.size() == 0 || arr.size() == 1)
            return 0;

        // Left
        int left = 0;
        for (; left < arr.size() - 1;)
        {
            if (arr[left] <= arr[left + 1])
                left++;
            else
                break;
        }

        // Right
        int right = arr.size() - 1;
        for (; right > 0;)
        {
            if (arr[right - 1] <= arr[right])
                right--;
            else
                break;
        }

        if (left >= right)
            return 0;

        // cout << "left: " << left << " "
        //      << "right: " << right << endl;

        int ans = min((int)arr.size() - 1 - left, right);

        for (int i = 0, j = right; i <= left && j < arr.size();)
        {
            if (arr[i] <= arr[j])
            {
                ans = min(ans, j - i - 1);
                i++;
            }
            else
            {
                j++;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    {
        vector<int> arr = {1, 2, 3, 10, 4, 2, 3, 5};
        cout << sol.findLengthOfShortestSubarray(arr) << endl;
    }

    {
        vector<int> arr = {5, 4, 3, 2, 1};
        cout << sol.findLengthOfShortestSubarray(arr) << endl;
    }

    {
        vector<int> arr = {1, 2, 3};
        cout << sol.findLengthOfShortestSubarray(arr) << endl;
    }
}