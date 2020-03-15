#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string removeKdigits(string num, int k) {
		int keep = num.size() - k;
		string res;
		for (int i = 0; i < num.size(); ++i) {
			while (res.size() > 0 && res.back() > num[i] && k > 0) {
				res.pop_back();
				k--;
			}
			res.push_back(num[i]);
		}
		res.erase(keep, string::npos);	// only keeps #keep characters

		// trim zeros
		int i = 0;
		while (i < (int)res.size() && res[i++] == '0');
		res.erase(0, i - 1);

		return res == "" ? "0" : res;
	}
};

int main() {
	string num = "1432219";
	int k = 3;
	Solution sol;
	cout << sol.removeKdigits(num, k) << endl;


}