#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	string reorganizeString(string S) {
		vector<int> count(26, 0);
		int most_freq = 0;
		for (int i = 0; i < S.length(); ++i) {
			if (++count[S[i] - 'a'] > count[most_freq]) {
				most_freq = S[i] - 'a';
			}
		}

		if (count[most_freq] > (S.length() + 1) / 2) return "";

		int idx = 0;
		while (count[most_freq] > 0) {
			S[idx] = char(most_freq + 'a');
			idx += 2;
			count[most_freq]--;
		}

		for (int i = 0; i < 26; ++i) {
			while (count[i] > 0) {
				if (idx >= S.length()) idx = 1;
				S[idx] = char(i + 'a');
				idx += 2;
				count[i]--;
			}
		}
		return S;
	}
};

int main() {
	string S = "abbabababbabbbaabaaaaabbbbabbbbbababbbabbabbb";
	Solution sol;
	cout << sol.reorganizeString(S) << endl;
}