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

// struct Node {
// 	int x;
// 	Node* next;
// 	Node(int m, Node* n) : x(m), next(n) {}
// };

// class Solution {
// public:
//     vector<int> numsSameConsecDiff(int N, int K) {
//         vector<vector<Node*> > m(N + 1, vector<Node*>(10, NULL));
//         vector<int> ans;

//         for (int x = 0; x <= 9; ++x) {
//         	m[1][x] = new Node(x, NULL);
//         }

//         for (int i = 2; i <= N; ++i) {
//         	for (int x = 0; x <= 9; ++x) {
//         		if (x + K <= 9) {
//         			if (m[i - 1][x + K]) {
//         				m[i][x] = new Node(x, m[i - 1][x + K]);
//         			}
//         		}
//         		if (x - K >= 0) {
//         			if (m[i - 1][x - K]) {
//         				m[i][x] = new Node(x, m[i - 1][x - K]);
//         			}
//         		}
//         	}
//         }
        
//         for (int i = 1; i <= 9; ++i) {
//         	if (m[N][i]) {
//         		int t = 0;
//         		Node* cur = m[N][i];
//         		while (cur) {
//         			t = 10 * t + cur->x;
//         			cur = cur->next;
//         		}
//         		ans.push_back(t);
//         	}
//         }
//         return ans;
//     }
// };

class Solution {
private:
	vector<int> ans;
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        for (int i = 1; i <= 9; ++i) {
        	dfs(i, N, K);
        }
        if (N == 1) ans.push_back(0);
        return ans;
    }
    void dfs(int x, int N, int K) {
    	if (to_string(x).size() == N) {
    		ans.push_back(x);
    		return;
    	}

    	// x.size() < N
    	int m = x % 10;
    	if (m + K <= 9) {
    		dfs(10 * x + (m + K), N, K);
    	}
    	if (m - K >= 0 && K) {
    		dfs(10 * x + (m - K), N, K);
    	}
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	int N = 2, K = 0;
	vector<int> ans = sol.numsSameConsecDiff(N, K);

	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << " ";
	}
	cout << endl;

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