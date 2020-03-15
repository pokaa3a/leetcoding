#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	string alphabetBoardPath(string target) {
		string res;
		int r1 = 0, c1 = 0;
		for (int i = 0; i < target.length(); ++i) {
			int r2, c2;
			lookup(target[i], r2, c2);
			res += move(r1, c1, r2, c2) + "!";
			r1 = r2;
			c1 = c2;
		}
		return res;
	}
private:
	string move(int r1, int c1, int r2, int c2) {
		string res;
		if (r1 == 5 && c1 == 0) {
			for (int i = 0; i < abs(r2 - r1); ++i) res += 'U';
			for (int i = 0; i < abs(c2 - c1); ++i) res += 'R';
		} else if (r2 == 5 && c2 == 0) {
			for (int i = 0; i < abs(c2 - c1); ++i) res += 'L';
			for (int i = 0; i < abs(r2 - r1); ++i) res += 'D';
		} else {
			if (r2 > r1) {
				for (int i = 0; i < abs(r2 - r1); ++i) res += 'D';
			} else {
				for (int i = 0; i < abs(r2 - r1); ++i) res += 'U';
			}
			if (c2 > c1) {
				for (int i = 0; i < abs(c2 - c1); ++i) res += 'R';
			} else {
				for (int i = 0; i < abs(c2 - c1); ++i) res += 'L';
			}
		}
		return res;
	}
	void lookup(char x, int& r, int& c) {
		r = (x - 'a') / 5;
		c = (x - 'a') % 5;
	}
};

int main() {
	string target = "vzv";
	Solution sol;
	cout << sol.alphabetBoardPath(target) << endl;
}