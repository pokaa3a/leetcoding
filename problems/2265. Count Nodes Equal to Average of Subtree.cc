#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int averageOfSubtree(TreeNode *root)
    {
        int ans = 0;
        average(root, ans);
        return ans;
    }

    // return: [subtree sum, # of subtree nodes]
    pair<int, int> average(TreeNode *root, int &ans)
    {
        if (!root)
        {
            return {0, 0};
        }

        auto [leftSum, leftNodes] = average(root->left, ans);
        auto [rightSum, rightNodes] = average(root->right, ans);

        int sum = leftSum + rightSum + root->val;
        int numNodes = leftNodes + rightNodes + 1;
        if (sum / numNodes == root->val)
        {
            ans++;
        }

        return {sum, numNodes};
    }
};

int main()
{
    TreeNode *p0 = new TreeNode(4);
    TreeNode *p1 = new TreeNode(8);
    TreeNode *p2 = new TreeNode(5);
    TreeNode *p3 = new TreeNode(0);
    TreeNode *p4 = new TreeNode(1);
    TreeNode *p5 = new TreeNode(6);
    p0->left = p1;
    p0->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->right = p5;

    Solution sol;
    cout << sol.averageOfSubtree(p0) << endl;
}