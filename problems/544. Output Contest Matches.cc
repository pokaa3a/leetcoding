#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	string findContestMatch(int n) {
		vector<string> vec;
		for (int i = 0; i < n; ++i) {
			vec.push_back(to_string(i + 1));
		}
		int count = n;
		while (count > 0) {
			for (int i = 0; i < count / 2; ++i) {
				vec[i] = "(" + vec[i] + "," + vec[count - 1 - i] + ")";
			}
			count /= 2;
		}
		return vec[0];
	}
};

int main() {
	Solution sol;
	int n = 8;
	cout << sol.findContestMatch(n) << endl;
}