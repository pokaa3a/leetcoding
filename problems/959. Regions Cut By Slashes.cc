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
    int regionsBySlashes(vector<string>& grid) {
        int N = grid.size();
        vector<int> group(4 * N * N, 0);
        for (int i = 0; i < 4 * N * N; ++i) group[i] = i;

        for (int i = 0; i < N; ++i) {
        	for (int j = 0; j < N; ++j) {
        		int id = i * N + j;

        		//   \ 0 /
        		//  1 \ / 2
        		//    / \
        		//   / 3 \

        		int id_0 = id * 4 + 0, id_1 = id * 4 + 1, id_2 = id * 4 + 2, id_3 = id * 4 + 3;
        		if (grid[i][j] == '/') {
        			uni(id_0, id_1, group);
        			uni(id_2, id_3, group);
        		} else if (grid[i][j] == '\\') {
        			uni(id_0, id_2, group);
        			uni(id_1, id_3, group);
        		} else {	// grid[i][j] == ' '
        			uni(id_0, id_1, group);
        			uni(id_0, id_2, group);
        			uni(id_0, id_3, group);
        		}

        		// connect top neighbor
        		if (i > 0) {
        			uni(id_0, ((i - 1) * N + j) * 4 + 3, group);
        		}
        		// connect left neighbor
        		if (j > 0) {
        			uni(id_1, (i * N + (j - 1)) * 4 + 2, group);
        		}
        	}
        }
        set<int> unique_groups;
        for (int i = 0; i < group.size(); ++i) {
        	int x = find(i, group);
        	unique_groups.insert(x);
        }
        return unique_groups.size();
    }
    int find(int x , vector<int>& group) {
    	if (x != group[x]) group[x] = find(group[x], group);
    	return group[x];
    }
    void uni(int x, int y, vector<int>& group) {
    	int a = find(x, group);
    	int b = find(y, group);
    	if (a != b) {
    		group[a] = b;
    	}
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	vector<string> grid;
	grid.push_back("//");
	grid.push_back("/ ");
	cout << sol.regionsBySlashes(grid) << endl;


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