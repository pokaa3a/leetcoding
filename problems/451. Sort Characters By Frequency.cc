#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>

using namespace std;

struct comp {
	bool operator() (const pair<char, int> &a, const pair<char, int> &b) const {
		return a.second < b.second;
	}
};

class Solution {
public:
	string frequencySort(string s) {
		string ans;
		unordered_map<char, int> m;
		for (int i = 0; i < s.length(); ++i) {
		// for (auto& c : s) {
			m[s[i]]++;
		}

		priority_queue<pair<char, int>, vector<pair<char, int> >, comp> q;
		for (unordered_map<char, int>::iterator it = m.begin(); it != m.end(); ++it) {
		// for (auto& [first, second] : m) { 
			q.push(make_pair((*it).first, (*it).second));
		}

		while (!q.empty()) {
			ans.insert(ans.end(), q.top().second, q.top().first);
			q.pop();
		}
		return ans;
	}
};

int main() {
	string s = "tree";

	Solution sol;
	cout << sol.frequencySort(s);
}