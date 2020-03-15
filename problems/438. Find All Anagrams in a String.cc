#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		vector<int> ans;
		if (s.length() < p.length()) return ans;

		vector<int> p_window(26, 0);
		vector<int> move_window(26, 0);
		for (int i = 0; i < p.length(); ++i) {
			p_window[p[i] - 'a']++;
			move_window[s[i] - 'a']++;
		}

		if (compTwoWindow(p_window, move_window)) {
			ans.push_back(0);
		}

		for (int i = 1; i < s.length() - p.length() + 1; ++i) {
			move_window[s[i - 1] - 'a']--;
			move_window[s[i + p.length() - 1] - 'a']++;
			if (compTwoWindow(p_window, move_window)) {
				ans.push_back(i);
			}
		}
		return ans;
	}
private:
	bool compTwoWindow(vector<int> &a, vector<int> &b) {
		for (int i = 0; i < a.size(); ++i) {
			if (a[i] != b[i]) return false;
		}
		return true;
	}
};

int main() {
	string s = "abab";
	string p = "ab";

	Solution sol;
	vector<int> ans = sol.findAnagrams(s, p);
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << " ";
	}
}