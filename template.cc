#include <cmath>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void traverse(TreeNode *root)
{
    if (!root)
        return;
    cout << root->val << endl;
    traverse(root->left);
    traverse(root->right);
}

/* Solution */
#define MOD 1000000007

int main()
{
    /* Solution */
    Solution sol;

    /* Test cases */
}