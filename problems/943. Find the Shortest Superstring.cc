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
#include <numeric>
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
    string shortestSuperstring(vector<string>& A) {
    	int ans_len = INT_MAX;
    	string ans = "";

    	for (int i = 0; i < A.size(); ++i) {
    		vector<string> A_copy = A;
    		swap(A_copy[0], A_copy[i]);
    		string res = findSuperstring(A_copy, ans_len);
    		if (res.size() < ans_len) {
    			ans_len = res.size();
    			ans = res;
    		}
    	}
    	return ans;
    }

    string findSuperstring(vector<string>& A, int upper_bnd) {
    	for (int len = A.size(); len != 1; len--) {
    		int max_overlap = INT_MIN;
    		int l, r;
    		string res_str = "";

    		for (int i = 0; i < len - 1; ++i) {
    			for (int j = i + 1; j < len; ++j) {
    				string str;
    				int res = findOverlappingPair(A[i], A[j], str);

    				if (res > max_overlap) {
    					max_overlap = res;
    					res_str = str;
    					l = i;
    					r = j;
    				}
    			}
    		}
    		if (max_overlap == INT_MIN) {
    			A[0] += A[len - 1];
    			if (A[0].size() > upper_bnd) return A[0];
    		} else {
    			A[l] = res_str;
    			A[r] = A[len - 1];
    		}
    	}
    	return A[0];
    }

    int findOverlappingPair(string str1, string str2, string& str) {
    	int len1 = str1.size(), len2 = str2.size();

    	int max1 = INT_MIN, max2 = INT_MIN;
    	string max_str1 = "", max_str2 = "";
    	// suffix of str1, prefix of str2
    	for (int i = min(len1, len2); i > 0; i--) {
    		if (str1.compare(len1 - i, i, str2, 0, i) == 0) {
    			max1 = i;
    			max_str1 = str1 + str2.substr(i);
    			break;
    		}
    	}
    	// suffix of str2, prefix of str1
    	for (int i = min(len1, len2); i > 0; i--) {
    		if (str2.compare(len2 - i, i, str1, 0, i) == 0) {
    			max2 = i;
    			max_str2 = str2 + str1.substr(i);
    		}
    	}
    	str = max1 > max2 ? max_str1 : max_str2;
    	return max(max1, max2);
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	vector<string> A;
	// 
	// A.push_back("efd");
	// A.push_back("ift");
	// A.push_back("dnete");
	// A.push_back("tef");
	// A.push_back("fdn");
	// 
	// A.push_back("ab");
	// A.push_back("ba");
	// 
	// A.push_back("alex");
	// A.push_back("loves");
	// A.push_back("leetcode");
	// 
	A.push_back("txvteggrtmylrxxknwub");
	A.push_back("lipgamrjnsfcqizch");
	A.push_back("teggrtmylrxxknwubv");
	A.push_back("uogduurswxthftx");
	A.push_back("akwnbruogduursw");
	A.push_back("uurswxthftxvteg");
	A.push_back("mylrxxknwubvlipga");
	A.push_back("ggrtmylrxxknwubvl");
	A.push_back("gzeindakwnbruogdu");
	A.push_back("thftxvteggrtmylrx");
	// 
	// A.push_back("a");
	cout << sol.shortestSuperstring(A) << endl;

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