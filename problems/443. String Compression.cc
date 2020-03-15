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

void traverse(TreeNode* root) {
	if (!root) return;
	cout << root->val << endl;
	traverse(root->left);
	traverse(root->right);
}

/* Solution */
const int MOD = 1000000007;
class Solution {
public:
    int compress(vector<char>& chars) {
        int k = 0;

        char cur_c = chars[0];
        int count = 1;
        for (int i = 1; i < chars.size(); i++) {
        	if (chars[i] == cur_c) count++;
        	else {
        		chars[k++] = cur_c;
        		if (count > 1){
	        		string cnt_s = to_string(count);
	        		for (int j = 0; j < cnt_s.size(); j++) {
	        			chars[k++] = cnt_s[j];
	        		}
        		}
        		cur_c = chars[i];
        		count = 1;
        	}
        }
        chars[k++] = cur_c;
        string cnt_s = to_string(count);
        if (count > 1) {
	        for (int j = 0; j < cnt_s.size(); j++) {
	        	chars[k++] = cnt_s[j];
	        }
        }
        chars = vector<char>(chars.begin(), chars.begin() + k);
        return k;
    }
};



int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	char c[] = {'a', 'a', 'b', 'c', 'c', 'c'};
	vector<char> chars(c, c + sizeof(c) / sizeof(char));
	cout << sol.compress(chars) << endl;
	for (int i = 0; i < chars.size(); i++) cout << chars[i] << " ";


	/* [1-D vector] */
	// int arr[] = {};
	// vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));

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