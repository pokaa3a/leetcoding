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
    vector<int> threeEqualParts(vector<int>& A) {
        int n_ones = 0;
        vector<int> ans(2, -1);
        for (int i = 0; i < A.size(); ++i) if (A[i] == 1) n_ones++;

        if (n_ones == 0) {
        	ans[0] = 0;
        	ans[1] = A.size() - 1;
        	return ans;
        }
        if (n_ones % 3 != 0) return ans;

        vector<int> first = find_first_and_end(0, A, n_ones);
        vector<int> second = find_first_and_end(first[1] + 1, A, n_ones);
        vector<int> third = find_first_and_end(second[1] + 1, A, n_ones);

        // cout << "1st: " << first[0] << ", " << first[1] << endl;
        // cout << "2nd: " << second[0] << ", " << second[1] << endl;
        // cout << "3rd: " << third[0] << ", " << third[1] << endl;

        if (!check(first, second, third, A)) return ans;
        int min_zeros = A.size() - 1 - third[1];
        // cout << "min_zeros = " << min_zeros << endl;

        if (first[1] + min_zeros >= second[0] ||
        	second[1] + min_zeros + 1 > third[0]) return ans;
        else {
        	ans[0] = first[1] + min_zeros;
        	ans[1] = second[1] + min_zeros + 1;
        } 
        return ans;
    }
    vector<int> find_first_and_end(int start, vector<int>& A, int n_ones) {
    	vector<int> res(2, 0);
    	int i = start;
    	while (i < A.size() && A[i] == 0) i++;
    	res[0] = i;

    	int cnt = 0;
    	while (i < A.size() && cnt < n_ones / 3) {
    		if (A[i] == 1) cnt++;
    		if (cnt == n_ones / 3) break;
    		else i++;
    	}
    	res[1] = i;

    	return res;
    }

    bool check(vector<int>& first, vector<int>& second, vector<int>& third, vector<int>& A) {
    	if (first[1] - first[0] != second[1] - second[0] ||
    		first[1] - first[0] != third[1] - third[0]) return false;
    	for (int i = 0; i <= first[1] - first[0]; ++i) {
    		if (A[first[0] + i] != A[second[0] + i] ||
    			A[first[0] + i] != A[third[0] + i]) return false;
    	}
    	return true;
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */

	/* [1-D vector] */
	// const int a = 1;
	// int arr[] = {};
	// vector<int> nums(arr, arr + a);
	int a[] = {0,0,0,0,0};
	vector<int> A(a, a + 5);
	vector<int> ans = sol.threeEqualParts(A);

	for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
	cout << endl; 

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