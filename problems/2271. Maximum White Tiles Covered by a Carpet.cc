#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maximumWhiteTiles(vector<vector<int> > &tiles, int carpetLen)
    {
        sort(tiles.begin(), tiles.end());
        vector<int> tilesSum(tiles.size());

        for (int i = 0; i < tiles.size(); ++i)
        {
            tilesSum[i] = (i == 0 ? 0 : tilesSum[i - 1]) + tiles[i][1] - tiles[i][0] + 1;
        }

        int ans = 0;
        int j = 0;
        for (int i = 0; i < tiles.size(); ++i)
        {
            int endIdx = tiles[i][1];
            int startIdx = endIdx - carpetLen + 1;

            while (j <= i && tiles[j][1] < startIdx)
            {
                j++;
            }

            int covered = tilesSum[i] - (j == 0 ? 0 : tilesSum[j - 1]);
            if (tiles[j][0] < startIdx)
            {
                covered -= startIdx - tiles[j][0];
            }

            ans = max(ans, covered);
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    {
        vector<vector<int> > tiles = {
            {1, 5}, {10, 11}, {12, 18}, {20, 25}, {30, 32}};
        int carpetLen = 10;
        cout << sol.maximumWhiteTiles(tiles, carpetLen) << endl;
    }

    {
        vector<vector<int> > tiles = {
            {10, 11}, {1, 1}};
        int carpetLen = 2;
        cout << sol.maximumWhiteTiles(tiles, carpetLen) << endl;
    }
}