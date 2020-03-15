#include <iostream>
#include <set>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	string findLongestWord(string s, vector<string>& d) {
		if (s.length() == 0) return "";
		vector<vector<int> > m(s.length(), vector<int>(26, s.length()));
		m.back()[s.back() - 'a'] = s.length() - 1;
		for (int i = s.length() - 2; i >= 0; --i) {
			m[i] = m[i + 1];
			m[i][s[i] - 'a'] = i;
		}

		string ans;
		for (int i = 0; i < d.size(); ++i) {
			if (canBeFormed(s, d[i], m)) {
				if (d[i].length() > ans.length()) {
					ans = d[i];
				} else if (d[i].length() == ans.length()) {
					set<string> ss;
					ss.insert(d[i]);
					ss.insert(ans);
					ans = *ss.begin();
				}
			}
		}
		return ans;
	}
private:
	bool canBeFormed(string s, string d, vector<vector<int> >& m) {
		// cout << "d: " << d << endl;
		int j = 0;
		for (int i = 0; i < d.length(); ++i) {
			// cout << "d[i]: " << d[i] << ", ";
			// cout << "j: " << j << ", ";
			if (j == s.length()) return false;
			int next = m[j][d[i] - 'a'];
			// cout << "next: " << next << endl;
			if (next == s.length()) return false;
			j = next + 1;
		}
		return true;
	}
};

int main() {
	string s = "abpcplea";
	vector<string> d;
	d.push_back("b");
	d.push_back("a");
	d.push_back("c");
	// d.push_back("plea");

	Solution sol;
	cout << sol.findLongestWord(s, d) << endl;
}