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
    int shortestBridge(vector<vector<int> >& A) {
        // look for one of two islands
        int first_i, first_j;
        bool found = false;
        for (first_i = 0; first_i < A.size(); ++first_i) {
        	for (first_j = 0; first_j < A[first_i].size(); ++first_j) {
        		if (A[first_i][first_j] == 1) {
        			found = true;
        			break;
        		}
        	}
        	if (found) break;
        }
        // look for edge
        queue<pair<int, int> > q;
        find_edge(first_i, first_j, A, q);

        // BFS
        int ans = -1;
        while (!q.empty()) {
        	int q_size = q.size();
        	ans++;
        	for (int k = 0; k < q_size; ++k) {
        		pair<int, int> n = q.front(); q.pop();
        		int i = n.first, j = n.second;

        		if (i > 0 && A[i - 1][j] != 2) {
        			if (A[i - 1][j] == 1) return ans;
        			q.push(make_pair(i - 1, j));
        			A[i - 1][j] = 2;
        		}
        		if (i < A.size() - 1 && A[i + 1][j] != 2) {
        			if (A[i + 1][j] == 1) return ans;
        			q.push(make_pair(i + 1, j));
        			A[i + 1][j] = 2;
        		}
        		if (j > 0 && A[i][j - 1] != 2) {
        			if (A[i][j - 1] == 1) return ans;
        			q.push(make_pair(i, j - 1));
        			A[i][j - 1] = 2;
        		}
        		if (j < A[0].size() - 1 && A[i][j + 1] != 2) {
        			if (A[i][j + 1] == 1) return ans;
        			q.push(make_pair(i, j + 1));
        			A[i][j + 1] = 2;
        		}
        	}
        }
        return 0;
    }
    void find_edge(int i, int j, vector<vector<int> >& A, 
    			   queue<pair<int, int> >& q) {
    	
    	if (i < 0 || i >= A.size() || j < 0 || j >= A[0].size()) return;
    	if (A[i][j] != 1) return;

    	A[i][j] = 2;

    	if ((i > 0 && A[i - 1][j] == 0) ||
    		(i < A.size() - 1 && A[i + 1][j] == 0) ||
    		(j > 0 && A[i][j - 1] == 0) ||
    		(j < A[0].size() - 1 && A[i][j + 1]) == 0) {
    		// cout << "push (" << i << ", " << j << ")" << endl;
    		q.push(make_pair(i, j));
    	}
    	find_edge(i - 1, j, A, q);
    	find_edge(i + 1, j, A, q);
    	find_edge(i, j - 1, A, q);
    	find_edge(i, j + 1, A, q);
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

	/* [2-D vector] */
	const int rows = 5;
	const int cols = 5;
	int arr[rows][cols] = {{1,1,1,1,1}, 
						   {1,0,0,0,1}, 
						   {1,0,1,0,1},
						   {1,0,0,0,1},
						   {1,1,1,1,1}};
	vector<vector<int> > grid;
	for (int r = 0; r < rows; ++r) {
		grid.push_back(vector<int>(arr[r], arr[r] + cols));
	}

	cout << sol.shortestBridge(grid) << endl;

	/* [String] */
	// string str = "";

}