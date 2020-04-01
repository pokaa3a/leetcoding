#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

// O(n^2)
class Solution {
public:
	int countSubstrings(string s) {
		int n = s.size();
		// pa[i]: [a, b, ...] means i-a, i-b, ... are palindromes
		vector<unordered_set<int>> pa(n, unordered_set<int>());
		
		// i-j is a palindrome if (i+1)-(j-1) is a palindrome and s[i] == s[j]
		pa[n - 1] = unordered_set<int>{n - 1};

		int ans = 0;
		for (int i = n - 1; i >= 0; i--) {
			for (int j = i; j < n; j++) {
				if (i == j) {
					pa[i].insert(j);
					ans++;
				} else if (i + 1 == j && s[i] == s[j]) {
					pa[i].insert(j);
					ans++;
				} else {
					if (s[i] == s[j] && pa[i + 1].find(j - 1) != pa[i + 1].end()) {
						pa[i].insert(j);
						ans++;
					}
				}
			}
		}
		return ans;
	}
};

int main() {
	Solution sol;

	string s = "aaa";
	cout << sol.countSubstrings(s) << endl;
}