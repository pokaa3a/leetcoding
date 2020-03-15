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

const int MOD = 1000000007;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

/* Solution */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> nums;
        while (head) {
        	nums.push_back(head->val);
        	head = head->next;
        }
        int n = nums.size();

        vector<int> ans(n, 0);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
        	int x = nums[i];
        	while (!st.empty() && st.top() <= x) {
        		st.pop();
        	}
        	if (st.empty()) ans[i] = 0;
        	else ans[i] = st.top();
        	st.push(x);
        }
        return ans;
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases

}