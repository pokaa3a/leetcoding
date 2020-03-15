#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
	// Encodes a tree to a string
	string serialize(TreeNode *root) {
		ostringstream out;
		mySerialize(root, out);
		return out.str();
	}

	// Decodes encoded string to a tree
	TreeNode* deserialize(string data) {
		if (!data.size()) return NULL;
		istringstream in(data);
		return myDeserialize(in);
	}

private:
	void mySerialize(TreeNode *node, ostringstream &out) {
		if (!node) return;
		out << node->val << " ";
		mySerialize(node->left, out);
		mySerialize(node->right, out);
	}

	TreeNode* myDeserialize(istringstream &in) {
		string val;
		in >> val;
		TreeNode *root = new TreeNode(stoi(val));
		while (in >> val)
			buildTree(root, stoi(val));
		return root;
	}
	void buildTree(TreeNode *root, int val) {
		if (val < root->val) {
			if (!root->left) {
				root->left = new TreeNode(val);
			} else {
				buildTree(root->left, val);
			}
		} else {
			if (!root->right) {
				root->right = new TreeNode(val);
			} else {
				buildTree(root->right, val);
			}
		}
	}
};

void preorder(TreeNode* n) {
	if (!n) cout << "NULL" << endl;
	cout << n->val << endl;
	if (n->left) preorder(n->left);
	if (n->right) preorder(n->right);
}

int main() {
	TreeNode *root = new TreeNode(8);
	root->left = new TreeNode(3);
	root->right = new TreeNode(10);
	root->left->left = new TreeNode(1);
	root->right->left = new TreeNode(9);
	root->right->right = new TreeNode(14);

	Codec codec;
	TreeNode *n = codec.deserialize(codec.serialize(root));
	preorder(n);
}