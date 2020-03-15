#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		if(numRows == 1) return s;
		string output = "";
		int max_dist = 2 * (numRows - 1);
		for (int i = 0; i < numRows; ++i) {
			string row = "";
			for (int j = i; j < s.length(); j += max_dist) {
				row += s[j];
				if (i == 0 || i == numRows - 1 || j + (max_dist - i * 2) >= s.length()) {
					continue;
				} else {
					row += s[j + (max_dist - i * 2)];
				}
			}
			output += row;
		}
		return output;
	}
};

int main(){
	Solution sol;
	string s = "PAYPALISHIRING";
	int numRows = 3;
	string res = sol.convert(s, numRows);
	cout << res << endl;
}