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
    bool wordBreak(string s, vector<string>& wordDict) {
        map<string, bool> hash;
        for(int i=0; i<wordDict.size(); i++){
            hash[wordDict[i]] = true;
        }
        
        vector<bool> dp(s.length()+1);
        dp[0] = true;
        
        for(int i=1; i<=s.length(); i++){
            for(int j=1; j<=i; j++){
                string str = s.substr(i-j,j);
                if(hash.find(str)!=hash.end()){
                    dp[i] = dp[i-j];
                    if(dp[i]) break;
                }
            }
        }
        return dp[s.length()];
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
    //  grid.push_back(vector<int>(arr[r], arr[r] + cols));
    // }

    /* [String] */
    // string str = "";

}