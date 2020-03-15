#include <iostream>
#include <string>
#include <stack>
using namespace std;

// class Solution {
// public:
// 	bool parseBoolExpr(string expression) {
// 		stack<char> opt;
// 		stack<char> val;
// 		for (int i = 0; i < expression.size(); ++i) {
// 			char c = expression[i];
// 			if (c == ',') continue;
// 			else if (c == '!' || c == '&' || c == '|') {
// 				opt.push(c);
// 			} else if (c == '(') {
// 				val.push(c);
// 			} else if (c == ')') {
// 				bool new_c = val.top() == 't' ? true : false;
// 				if (opt.top() == '!') {
// 					val.pop();	// 't' / 'f'
// 					new_c = !new_c;
// 				} else if (opt.top() == '&') {
// 					while (val.top() != '(') {
// 						new_c &= val.top() == 't' ? true : false;
// 						val.pop();
// 					}
// 				} else if (opt.top() == '|') {
// 					while (val.top() != '(') {
// 						new_c |= val.top() == 't' ? true : false;
// 						val.pop();
// 					}
// 				}
// 				opt.pop();
// 				val.pop();	// '('
// 				val.push(new_c == true ? 't' : 'f');
// 			} else {
// 				assert(c == 't' || c == 'f');
// 				val.push(c);
// 			}
// 		}
// 		return val.top() == 't' ? true : false;
// 	}
// };

class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> opt_st;
        stack<char> boo_st;
        for (int i = 0; i < expression.size(); ++i) {
            char c = expression[i];
            if (c == ',') continue;
            else if (c == '!' || c == '&' || c == '|') {
                opt_st.push(c);
            } else {
                if (c == ')') {
                    bool tmp = boo_st.top() == 't' ? true : false;
                    if (opt_st.top() == '!') {
                        boo_st.pop();
                        tmp = !tmp;
                    } else if (opt_st.top() == '&') {
                        while (boo_st.top() != '(') {
                            tmp &= boo_st.top() == 't' ? true : false;
                            boo_st.pop();
                        }
                    } else {    // '|'
                        while (boo_st.top() != '(') {
                            tmp |= boo_st.top() == 't' ? true : false;
                            boo_st.pop();
                        }
                    }
                    opt_st.pop();
                    boo_st.pop(); // '('
                    boo_st.push(tmp ? 't' : 'f');
                } else {
                    boo_st.push(c);
                }
            }
        }
        return boo_st.top() == 't' ? true : false;
    }
};

int main() {
	string expression = "|(&(t,f,t),!(t))";
	Solution sol;
	cout << sol.parseBoolExpr(expression) << endl;
}