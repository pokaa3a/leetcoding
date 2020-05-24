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
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if (!root) return "#";
        string code = "";
        code += to_string(root->val);
        for (int i = 0; i < root->children.size(); i++) {
            code += " " + serialize(root->children[i]);
        }
        return code + " " + "#";
    }
	
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        Node* node;
        stringstream ss(data);
        return my_deserialize(ss);
    }
    Node* my_deserialize(stringstream& ss) {
        string token;
        getline(ss, token, ' ');
        if (token == "#") {
            return NULL;
        }
        
        Node* node = new Node(stoi(token));
        Node* next = my_deserialize(ss);
        while (next) {
            node->children.push_back(next);
            next = my_deserialize(ss);
        }
        return node;
    }
};

int main() {
	/* Solution */
	Solution sol;

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