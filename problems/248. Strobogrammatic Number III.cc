#include <iostream>
#include <string>
#include <unordered_map>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
	int strobogrammaticInRange(string low, string high) {
		int n1 = low.size(), n2 = high.size();
		int ans = 0;
		vector<string> s1 = compute_str(n1);
		for (auto s : s1) {
			if (inTolerance(s, low, high)) ans++;
		}
		if (n1 != n2) {
			vector<string> s2 = compute_str(n2);
			for (auto s : s2) {
				if (inTolerance(s, low, high)) {
					ans++;
				}
			}
		}
		for (int n = n1 + 1; n < n2; n++) {
			ans += compute_num(n);
			// cout << "n: " << n << " num = " << compute_num(n) << endl;
		}
		return ans;
	}
	bool inTolerance(string s, string low, string high) {
		if (s.size() > 1 && s[0] == '0') return false;

		// low
		if (s.size() < low.size()) return false;
		else if (s.size() == low.size()) {
			for (int i = 0; i < s.size(); i++) {
				if (s[i] < low[i]) return false;
				else if (s[i] > low[i]) break;
			}
		}

		// high
		if (s.size() > high.size()) return false;
		else if (s.size() == high.size()) {
			for (int i = 0; i < s.size(); i++) {
				if (s[i] > high[i]) return false;
				else if (s[i] < high[i]) break;
			}
		}
		return true;
	}

	vector<string> compute_str(int n) {
		if (n == 0) return vector<string>{""};
		if (n == 1) return vector<string>{"0", "1", "8"};
		vector<string> v = compute_str(n-2);
		vector<string> res;
		for (auto s : v) {
			res.push_back("0" + s + "0");
			res.push_back("1" + s + "1");
			res.push_back("6" + s + "9");
			res.push_back("8" + s + "8");
			res.push_back("9" + s + "6");
		}
		return res;
	}
	int compute_num(int n) {
		int num_choice = n / 2;
		int res = 4;
		res *= pow(5, num_choice - 1);
		if (num_choice * 2 < n) {
			res *= 3;
		}
		return res;
	}
};

int main() {
	Solution sol;
	string low = "0", high = "1680";
	cout << sol.strobogrammaticInRange(low, high) << endl;
}