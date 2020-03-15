#include <iostream>
#include <string>
#include <sstream>
#include <stack>
using namespace std;

class Solution {
public:
	bool isValidSerialization(string preorder) {
		if (preorder.length() == 0) return false;
		istringstream ss(preorder);
		string s;

		stack<char> st;
		while (getline(ss, s, ',')) {
			char c = s[0];
			if (c == '#') {
				while (!st.empty() && st.top() == '#') {
					st.pop();
					if (st.empty()) return false;
					st.pop();
				}
			}
			st.push(c);
		}
		if (st.size() == 1 && st.top() == '#') return true;
		else return false;
	}
};


int main() {
	string preorder = "9,#,92,#,#";
	Solution sol;
	cout << sol.isValidSerialization(preorder) << endl;
}