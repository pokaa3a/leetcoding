#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
	struct comp {
		bool operator() (const pair<int, string>& a, const pair<int, string>& b) {
			if (a.first != b.first) return a.first > b.first;
			return a.second < b.second;
		}
	};
public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		priority_queue<pair<int, string>, vector<pair<int, string>>, comp> pq;
		unordered_map<string, int> freq;

		for (auto w : words) {
			freq[w]++;
		}
		for (auto p : freq) {
			pq.push(make_pair(p.second, p.first));
			while (pq.size() > k) pq.pop();
		}

		vector<string> ans(k, "");
		for (int i = k - 1; i >= 0; i--) {
			ans[i] = pq.top().second;
			pq.pop();
		}
		return ans;
	}
};

int main() {
	vector<string> words = {"a", "aa", "aaa"};
	int k = 1;

	Solution sol;
	vector<string> ans = sol.topKFrequent(words, k); 
	for (auto s : ans) cout << s << " ";
	cout << endl;
}