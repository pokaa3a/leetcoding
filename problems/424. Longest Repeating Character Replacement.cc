#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int characterReplacement(string s, int k) {
		if (!s.length()) return 0;
		int start = 0, end = 0, max_freq = 0, ans = 0;
		vector<int> count(26, 0);

		for (; end < s.length(); end++) {
			count[s[end] - 'A']++;
			max_freq = max(max_freq, count[s[end] - 'A']);
			// if not sufficient
			if ((end - start + 1) > k + max_freq) {
				ans = max(end - start, ans);
				count[s[start] - 'A']--;
				start++;
			}
		}
		return max(ans, end - start);
	}
};

int main() {
	string s = "ABAB";
	int k = 2;
	Solution sol;
	cout << sol.characterReplacement(s, k) << endl;
}