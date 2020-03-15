#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	int longestSubstring(string s, int k) {
		int n_distinct = unordered_set<char>(s.begin(), s.end()).size();
		int res = 0;

		for (int i = 1; i <= n_distinct; ++i) {
			vector<int> char_count(26, 0);
			for (int p = 0, q = 0, d = 0, n = 0; q < s.size(); res = d == i && n == i ? max(res, q - p) : res) {
				if (d <= i) {
					d = char_count[s[q] - 'a'] == 0 ? d + 1 : d;
					n = ++char_count[s[q] - 'a'] == k ? n + 1 : n;
					q++;
				} else {
					n = char_count[s[p] - 'a'] == k ? n - 1 : n;
					d = --char_count[s[p] - 'a'] == 0 ? d - 1 : d;
					p++;
				}
			}
		}
		return res;
	}
};

int main() {
	string s = "aaabb";
	Solution sol;
	cout << sol.longestSubstring(s, 3) << endl;
}