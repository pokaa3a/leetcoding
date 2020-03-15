#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
    	max_leaf_vec.resize(arr.size(), vector<int>(arr.size(), -1));
    	sum_vec.resize(arr.size(), vector<int>(arr.size(), -1));
    	int res, max_leaf;
    	dp(0, arr.size() - 1, max_leaf, res, arr);
    	return res;
    }
private:
	vector<vector<int> > max_leaf_vec;
	vector<vector<int> > sum_vec;
	void dp(int i, int j, int& max_leaf, int& sum, vector<int>& arr) {
		if (max_leaf_vec[i][j] != -1 && sum_vec[i][j] != -1) {
			max_leaf = max_leaf_vec[i][j];
			sum = sum_vec[i][j];
			return;
		}
		if (i == j) {
			max_leaf = arr[i];
			sum = 0;
			return;
		}
		sum = INT_MAX;
		max_leaf = 0;
		for (int x = i; x < j; ++x) {
			int left_max_leaf, left_sum, right_max_leaf, right_sum;
			dp(i, x, left_max_leaf, left_sum, arr);
			dp(x + 1, j, right_max_leaf, right_sum, arr);
			sum = min(sum, left_max_leaf * right_max_leaf + left_sum + right_sum);
			max_leaf = max(left_max_leaf, right_max_leaf);
		}
		max_leaf_vec[i][j] = max_leaf;
		sum_vec[i][j] = sum;
	}
};

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        stack<int> st;
        int ans = 0;
        for (int i = 0; i < arr.size(); ++i) {
            while (!st.empty() && st.top() <= arr[i]) {
                int mid = st.top();
                st.pop();
                ans += mid * min((st.empty() ? INT_MAX : st.top()), arr[i]);
            }
            st.push(arr[i]);
        }
        if (st.size() > 1) {
            int last = st.top();
            st.pop();
            while (!st.empty()) {
                ans += st.top() * last;
                last = st.top();
                st.pop();
            }
        }
        return ans;
    }
};

int main() {
	int a[] = {6, 2, 4};
	vector<int> arr(a, a + 3);

	Solution sol;
	cout << sol.mctFromLeafValues(arr) << endl;
}