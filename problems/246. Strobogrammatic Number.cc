#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
	bool isStrobogrammatic(string num) {
		map<char, char> rotate;
		rotate['0'] = '0';
		rotate['1'] = '1';
		rotate['2'] = '#';
		rotate['3'] = '#';
		rotate['4'] = '#';
		rotate['5'] = '#';
		rotate['6'] = '9';
		rotate['7'] = '#';
		rotate['8'] = '8';
		rotate['9'] = '6';


		string rotated = "";
		for (int i = num.length() - 1; i >= 0; --i) {
			rotated = rotated + rotate[num[i]];
		}
		return rotated == num;
	}
};

int main() {
	Solution sol;
	cout << sol.isStrobogrammatic("962") << endl;
}