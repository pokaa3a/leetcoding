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

/* Solution */
class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size(), n2 = arr2.size();
      	reverse(arr1.begin(), arr1.end());
      	reverse(arr2.begin(), arr2.end());

      	int carry = 0;
      	vector<int> ans;
      	int i = 0;
      	while (i < max(n1, n2) || carry != 0) {
      		int a1 = i < n1 ? arr1[i] : 0;
      		int a2 = i < n2 ? arr2[i] : 0;
      		int sums = a1 + a2 + carry;
      		if (sums == 0) {
      			ans.push_back(0);
      			carry = 0;
      		} else if (sums == 1) {
      			ans.push_back(1);
      			carry = 0;
      		} else if (sums == 2) {
      			ans.push_back(0);
      			carry = -1;
      		} else if (sums == 3) {
      			ans.push_back(1);
      			carry = -1;
      		} else if (sums == -1) {
      			ans.push_back(1);
      			carry = 1;
      		}
      		i++;
      	}
      	reverse(ans.begin(), ans.end());
      	int first_non_zero = 0;
      	while (first_non_zero < ans.size() && ans[first_non_zero] == 0) {first_non_zero++;}
      	// cout << "first non zero: " << first_non_zero << endl;
      	if (first_non_zero >= ans.size()) return vector<int>(1, 0);
      	vector<int> ans2(ans.begin() + first_non_zero, ans.end());
      	return ans2;
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases
	int a1[] = {0};
	int a2[] = {0};
	vector<int> arr1(a1, a1 + 1);
	vector<int> arr2(a2, a2 + 1);
	vector<int> ans = sol.addNegabinary(arr1, arr2);
	for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
	cout << endl;
}