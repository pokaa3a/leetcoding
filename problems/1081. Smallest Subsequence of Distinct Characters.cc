#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <stack>
#include <map>
using namespace std;

// class Solution {
// public:
//     string smallestSubsequence(string text) {
//     	map<char, int> last;
//     	for (int i = 0; i < text.size(); ++i) {
//     		last[text[i]] = i;
//     	}

//     	set<char> in_stack;
//     	stack<char> st;
//     	for (int i = 0; i < text.size(); ++i) {
//     		char c = text[i];
//     		if (st.empty()) {
//     			st.push(c);
//     			in_stack.insert(c);
//     		} else {
//     			if (in_stack.count(c) == 0) {
// 	    			while (!st.empty() && st.top() > c && last[st.top()] > i) {
// 	    				in_stack.erase(st.top());
// 	    				st.pop();
// 	    			}
// 	    			st.push(c);
// 	    			in_stack.insert(c);
//     			}
//     		}
//     	}
//     	string res;
//     	while (!st.empty()) {
//     		res += st.top();
//     		st.pop();
//     	}
//     	reverse(res.begin(), res.end());
//     	return res;
//     }
// };

class Solution {
public:
    string smallestSubsequence(string text) {
        stack<char> st;
        set<char> in_stack;
        for (int i = 0; i < text.size(); ++i) {
            char c = text[i];
            if (in_stack.count(c) > 0) continue;
            while (!st.empty() && c < st.top() && text.find(st.top(), i) != string::npos) {
                in_stack.erase(st.top());
                st.pop();
            }
            st.push(c);
            in_stack.insert(c);
        }
        
        string ans = "";
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};

int main() {
	// string text = "leetcode";
	// Solution sol;
	// string res = sol.smallestSubsequence(text);
	// cout << res << endl;

    string t = "leetcode";
    cout << t.find('e', 3) << endl;
}