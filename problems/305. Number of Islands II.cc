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
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        int k = positions.size();
        vector<int> group(k);
        unordered_map<int, int> pos2idx;
        
        int dirs[] = {-1, 0, 1, 0, -1};
        
        int num_islands = 0;
        vector<int> output;
        for (int i = 0; i < k; i++) {
            int r = positions[i][0], c = positions[i][1];
            int pos = r * n + c;
            
            if (pos2idx.count(pos)) {
                output.push_back(num_islands);
                continue;
            }
            
            pos2idx[pos] = i;
            group[i] = i;
            
            num_islands++;
            for (int j = 0; j < 4; j++) {
                int nb_r = r + dirs[j], nb_c = c + dirs[j + 1];
                if (nb_r >= 0 && nb_r < m &&
                    nb_c >= 0 && nb_c < n) {
                    if (pos2idx.count(nb_r * n + nb_c)) {
                        int this_island = find(i, group);
                        int nb_island = find(pos2idx[nb_r * n + nb_c], group);
                        if (this_island != nb_island) {
                            group[this_island] = nb_island;
                            num_islands--;
                        }
                    }
                }
            }
            output.push_back(num_islands);
        }
        return output;
    }
    int find(int x, vector<int>& group) {
        if (x != group[x]) group[x] = find(group[x], group);
        return group[x];
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	int m = 3, n = 3;
	vector<vector<int>> positions = {{0,0}, {0,1}, {1,2}, {2,1}};
	vector<int> res = sol.numIslands2(m, n, positions);

	for (int x : res) cout << x << endl;

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