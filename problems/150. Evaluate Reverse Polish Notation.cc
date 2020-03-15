#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	int evalPRN(vector<string>& tokens) {
		stack<int> s;
		for (int i = 0; i < tokens.size(); ++i) {
			if (tokens[i] == "+") {
				int a = s.top(); s.pop();
				int b = s.top(); s.pop();
				s.push(b + a);	
			} else if (tokens[i] == "-") {
				int a = s.top(); s.pop();
				int b = s.top(); s.pop();
				s.push(b - a);	
			} else if (tokens[i] == "*") {
				int a = s.top(); s.pop();
				int b = s.top(); s.pop();
				s.push(b * a);	
			} else if (tokens[i] == "/") {
				int a = s.top(); s.pop();
				int b = s.top(); s.pop();
				s.push(b / a);	
			} else {
				s.push(stoi(tokens[i]));
			}
		}
		return s.top();
	}
};

int main() {
	string array[] = {"4", "13", "5", "/", "+"};
	vector<string> tokens(array, array+5);
	Solution sol;
	cout << sol.evalPRN(tokens) << endl;
}