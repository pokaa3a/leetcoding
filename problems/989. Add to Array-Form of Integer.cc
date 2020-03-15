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
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int carry = 0;
        for (int i = A.size() - 1; i >= 0; i--) {
        	int k = K % 10;
        	int a = A[i];
        	int sum = k + a + carry;
        	carry = sum / 10;
        	sum %= 10;
        	K /= 10;
        	A[i] = sum;
        }
        while (K > 0 || carry > 0) {
        	int k = K % 10;
        	int sum = k + carry;
        	carry = sum / 10;
        	sum %= 10;
        	K /= 10;
        	A.insert(A.begin(), sum);
        } 

        if (carry > 0) {
        	A.insert(A.begin(), carry);
        }
        return A;
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases
	int a[] = {9,9};
	vector<int> A(a, a + 2);
	int K = 111;
	vector<int> res = sol.addToArrayForm(A, K);
	for (int i = 0; i < res.size(); ++i) cout << res[i] << " ";
	cout << endl;
}