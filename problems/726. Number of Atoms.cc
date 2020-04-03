#include <iostream>
#include <stack>
#include <map>
#include <string>
using namespace std;

class Solution {
public:
    string countOfAtoms(string formula) {
        stack<map<string, int>> st;
        st.push(map<string, int>());

        string ans = "";
        int n = formula.size(), i = 0;
        formula += '#';	// dummy char to prevent out of range
        while (i < n) {
        	if (formula[i] == '(') {
        		st.push(map<string, int>());
        		i++;
        	} else if (formula[i] == ')') {
        		i++;
        		int num = getNum(formula, i, n);
        		map<string, int> atoms = st.top();
        		st.pop();
        		for (auto atom : atoms) {
        			st.top()[atom.first] += atom.second * num;
        		}
        	} else if (isupper(formula[i])) {
        		string atom;
        		int num;
        		if (islower(formula[i + 1])) {
        			atom = formula.substr(i, 2);
        			i += 2;
        			num = getNum(formula, i, n);
        		} else {
        			atom = formula.substr(i, 1);
        			i++;
        			num = getNum(formula, i, n);
        		}
        		st.top()[atom] += num;
        	} else {
        		assert(false);
        	}
        }
        for (auto atom : st.top()) {
        	ans += atom.first;
        	if (atom.second > 1)
        		ans += to_string(atom.second);
        }
        return ans;
    }
    int getNum(string& formula, int& i, int n) {
    	if (!isdigit(formula[i])) return 1;

    	int tmp = i;
    	while (i < n && isdigit(formula[i])) i++;
    	int num = stoi(formula.substr(tmp, i - tmp));
    	return num;
    }
};

int main() {
	string formula = "K4(ON(SO3)2)2";

	Solution sol;
	cout << sol.countOfAtoms(formula) << endl; 
}
