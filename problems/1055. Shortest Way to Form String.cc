#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int shortestWay(string source, string target) {
		vector<vector<int> > dict(source.length(), vector<int>(26, source.length()));
		dict.back()[source[source.length() - 1] - 'a'] = source.length() - 1;
		for (int i = source.length() - 2; i >= 0; --i) {
			dict[i] = dict[i + 1];
			dict[i][source[i] - 'a'] = i;
		}

		int ans = 1, j = 0;
		for (int i = 0; i < target.length(); ++i) {
			if (j == 0 && dict[j][target[i] - 'a'] >= source.length()) return -1;

			j = dict[j][target[i] - 'a'] + 1;
			
			if (j == source.length()) {
				if (i != target.length() - 1) {
					ans++;
				}
				j = 0;
			} else if (j == source.length() + 1) {
				if (i == target.length() - 1) {
					if (dict[0][target[i] - 'a'] != source.length()) {
						ans++;
					} else {
						return -1;
					}
				} else {
					j = 0;
					i--;
					ans++;
				}
			}
		}
		return ans;
	}
};


int main() {
	// string source = "adbsc", target = "addddddddddddsbc";
	string source = "abc", target = "abcdbc";
	Solution sol;
	cout << sol.shortestWay(source, target) << endl;
}