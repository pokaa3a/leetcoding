#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int expressiveWords(string S, vector<string>& words) {
		int n = S.size();
		vector<pair<char, int>> record;
		char c = '#';
		int count = 0;
		for (int i = 0; i < n; i++) {
			if (i == 0) {
				c = S[i];
				count = 1;
				continue;
			}
			if (S[i] != S[i - 1]) {
				record.push_back(make_pair(c, count));
				c = S[i];
				count = 1;
			} else {
				count++;
			}
			if (i == n - 1) {
				record.push_back(make_pair(c, count));
			}
		}
		int ans = 0;
		for (string w : words) {
			char w_c = '#';
			int w_count = 0, idx = 0;
			bool valid = true;
			for (int i = 0; i < w.size(); i++) {
				if (i == 0) {
					w_c = w[i];
					w_count = 1;
					continue;
				}
				if (w[i] != w[i - 1]) {
					if (record[idx].second < 3) {
						if (w_c != record[idx].first || w_count != record[idx].second) {
							valid = false;
							break;
						}
					} else {	// cont >= 3
						if (w_c == record[idx].first && (w_count >= 1 && w_count <= record[idx].second)) {
							valid = true;
						} else {
							valid = false;
							break;
						}
					}
					w_c = w[i];
					w_count = 1;
					idx++;
				} else {
					w_count++;
				}
				if (i == w.size() - 1) {
					if (record[idx].second < 3) {
						if (w_c != record[idx].first || w_count != record[idx].second) {
							valid = false;
							break;
						}
					} else {
						if (w_c == record[idx].first && (w_count >= 1 && w_count <= record[idx].second)) {
							valid = true;
						} else {
							valid = false;
							break;
						}
					}
					idx++;
				}
			}
			if (valid && idx == record.size()) {
				ans++;
			}
		}
		return ans;
	}
};

int main() {
	string S = "abcd";
	vector<string> words = {"abc"};
	Solution sol;
	cout << sol.expressiveWords(S, words) << endl;
}