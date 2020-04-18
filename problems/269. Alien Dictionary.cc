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
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> graph;
        unordered_map<char, int> status;    // 0: not visited, 1: visited, 2: added
        for (string word : words) {
            for (char c : word) {
                graph[c] = unordered_set<char>();
                status[c] = 0;
            }
        }
        
        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i], w2 = words[i + 1];
            
            for (int j = 0; j < min(w1.size(), w2.size()); j++) {
                if (w1[j] != w2[j]) {
                    // w2[j] > w1[j]
                    if (graph[w1[j]].count(w2[j])) return "";
                    graph[w2[j]].insert(w1[j]);
                    break;
                }
                if (j == min(w1.size(), w2.size()) - 1 && w1.size() > w2.size()) return ""; 
            }
        }
        
        // topological sort
        stack<char> stk;
        for (auto p : graph) {
            if (!tp_sort(p.first, graph, status, stk)) return "";
        }
        
        string output = "";
        while (!stk.empty()) {
            output = stk.top() + output;
            stk.pop();
        }
        return output;
    }
    // return false if a cycle is detected
    bool tp_sort(char c, unordered_map<char, unordered_set<char>>& graph, unordered_map<char, int>& status,
                 stack<char>& stk) {
        if (status[c] == 1) {
            // visit twice
            return false;
        } else if (status[c] == 2) {
            // already added
            return true;
        }
        status[c] = 1;
        for (char e : graph[c]) {
            if (!tp_sort(e, graph, status, stk)) return false;
        }
        status[c] = 2;
        stk.push(c);
        return true;
    }
};

int main() {
	/* Solution */
	Solution sol;

	vector<string> words = {"bsusz","rhn","gfbrwec","kuw","qvpxbexnhx","gnp","laxutz","qzxccww"};
	/* Test cases */

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