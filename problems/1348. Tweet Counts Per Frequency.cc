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
class TweetCounts {
	unordered_map<string, vector<int> > records;
public:
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        if (records.find(tweetName) == records.end()) {
        	records[tweetName] = vector<int>();
        }
        records[tweetName].push_back(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int delta = 60;
        if (freq == "hour") delta *= 60;
        else if (freq == "day") delta *= 60 * 24;

        vector<int> ans((endTime - startTime) / delta + 1, 0);
        for (int i = 0; i < records[tweetName].size(); ++i) {
        	if (records[tweetName][i] >= startTime && records[tweetName][i] <= endTime) {
        		int interval = (records[tweetName][i] - startTime) / delta;
        		ans[interval]++;
        	}
        }
        return ans;
    }
};



int main() {
	/* Solution */
	TweetCounts TC;

	TC.recordTweet("tweet3", 0);
	TC.recordTweet("tweet3", 60);
	TC.recordTweet("tweet3", 10);

	vector<int> r = TC.getTweetCountsPerFrequency("minute", "tweet3", 0, 59);
	for (int i = 0; i < r.size(); ++i) cout << r[i] << " ";
	cout << endl;

	r = TC.getTweetCountsPerFrequency("minute", "tweet3", 0, 60);
	for (int i = 0; i < r.size(); ++i) cout << r[i] << " ";
	cout << endl;

	TC.recordTweet("tweet3", 120);
	r = TC.getTweetCountsPerFrequency("hour", "tweet3", 0, 210);
	for (int i = 0; i < r.size(); ++i) cout << r[i] << " ";



	/* Test cases */

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