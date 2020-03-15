#include <iostream>
#include <map>
#include <string>
using namespace std;

class Solution {
public:
	int numTilePossibilities(string tiles) {
		map<char, int> count;
		for (int i = 0; i < tiles.size(); ++i) {
			count[tiles[i]]++;
		}

		int n = count.size();
		int res = 0;
		for (int i = 1; i <= tiles.size(); ++i) {
			res += dfs(count, i);
		}
		return res;
	}
private:
	int dfs(map<char, int>& count, int len) {
		if (len == 0) return 1;

		int res = 0;
		for (map<char, int>::iterator it = count.begin(); it != count.end(); ++it) {
			if (it->second > 0) {
				it->second--;
				res += dfs(count, len - 1);
				it->second++;
			}
		}
		return res;
	}
};



int main() {
	string tiles = "AAABBC";
	Solution sol;
	cout << sol.numTilePossibilities(tiles) << endl;
}