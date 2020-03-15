#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		if (s1.length() > s2.length()) return false;
        vector<int> s1_permutation(26, 0);
        vector<int> s2_permutation(26, 0);
		for (int i = 0; i < s1.length(); ++i) {
			s1_permutation[s1[i] - 'a']++;
			s2_permutation[s2[i] - 'a']++;
		}
		for (int i = 0; i <= s2.length() - s1.length(); ++i) {
			if (s1_permutation == s2_permutation) return true;
			s2_permutation[s2[i] - 'a']--;
			s2_permutation[s2[i + s1.length()] - 'a']++;
		}
		return false;
	}
};

int main() {
	string s1 = "ab";
	string s2 = "ba";
	Solution sol;
	cout << sol.checkInclusion(s1, s2) << endl;
}