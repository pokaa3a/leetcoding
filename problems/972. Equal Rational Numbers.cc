#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <queue>
#include <stack>
#include <sstream>
#include <cmath>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/* Solution */
const int MOD = 1000000007;
class Solution {
public:
    bool isRationalEqual(string S, string T) {
    	string s_int, s_nrep, s_rep, t_int, t_nrep, t_rep;
    	parse(S, s_int, s_nrep, s_rep);
    	parse(T, t_int, t_nrep, t_rep);

    	rectify(s_int, s_nrep, s_rep);
    	rectify(t_int, t_nrep, t_rep);

    	// cout << "S: [" << s_int << "] [" << s_nrep << "] [" << s_rep << "]" << endl;
    	// cout << "T: [" << t_int << "] [" << t_nrep << "] [" << t_rep << "]" << endl;
    	return s_int == t_int && s_nrep == t_nrep;
    }

    void parse(string S, string& s_int, string& s_nrep, string& s_rep) {
    	s_int = S.substr(0, S.find('.'));
    	string f = "";
    	if (S.find('.') != string::npos) {
    		f = S.substr(S.find('.') + 1);
    		s_nrep = f.substr(0, f.find('('));
    	}
    	if (f.find('(') != string::npos) {
    		s_rep = f.substr(f.find('(') + 1, f.find(')') - f.find('(') - 1);
    	} else {
    		s_rep = "";
    	}

    	if (s_nrep.size() && s_rep.size() == 0) {
    		s_nrep = stoi(s_nrep) == 0 ? "" : s_nrep;
    	}
    	if (s_rep.size()) {
    		s_rep = stoi(s_rep) == 0 ? "" : s_rep;
    	}
    }
    void rectify(string& s_int, string& s_nrep, string& s_rep) {
    	if (s_rep.find('9') != string::npos && 
    		s_rep.size() == count(s_rep.begin(), s_rep.end(), '9')) {
    		int n_nrep = s_nrep.size() > 0 ? stoi(s_nrep) : 0;
    		if (to_string(n_nrep + 1).size() > s_nrep.size()) {
    			s_int = to_string(stoi(s_int) + 1);
    			s_nrep = "";
    		} else {
    			int tmp = s_nrep.size();
    			s_nrep = to_string(stoi(s_nrep) + 1);
    			while (s_nrep.size() < tmp) s_nrep = "0" + s_nrep;
    		}
    		s_rep = "";
    	}
    	if (s_rep.size()) {
    		while (s_nrep.size() < 20) {
    			s_nrep += s_rep;
    		}
    	}
    	s_rep = "";
    	s_nrep = s_nrep.substr(0, 20);
    }
};

int main() {
	/* Solution */
	Solution sol;
	/* Test cases */
	// string S = "1.001(01)", T = "1.00(10)";
	string S = "1.0", T = "1.";
	cout << sol.isRationalEqual(S, T);

	/* [1-D vector] */
	// const int a = 1;
	// int arr[] = {};
	// vector<int> nums(arr, arr + a);

	/* [2-D vector] */
	// const int rows = 1;
	// const int cols = 1;
	// int arr[rows][cols] = {{1}};
	// vector<vector<int> > grid;
	// for (int r = 0; r < rows; ++r) {
	// 	grid.push_back(vector<int>(arr[r], arr[r] + cols));
	// }

	/* [String] */
	// string str = "";

}