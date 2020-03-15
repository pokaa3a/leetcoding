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
    vector<vector<int> > highFive(vector<vector<int> >& items) {
        map<int, priority_queue<int, vector<int>, greater<int> > > id_to_q;
        for (int i = 0; i < items.size(); ++i) {
        	int id = items[i][0];
        	int score = items[i][1];
        	if (id_to_q.find(id) == id_to_q.end()) {
        		id_to_q[id] = priority_queue<int, vector<int>, greater<int> >();
        	}
        	id_to_q[id].push(score);
        	if (id_to_q[id].size() > 5) id_to_q[id].pop();
        }
        vector<vector<int> > ans;
        for (map<int, priority_queue<int, vector<int>, greater<int> > >::iterator it = id_to_q.begin(); 
        	 it != id_to_q.end(); ++it) {
        	int x[] = {it->first, mean(it->second)};
        	ans.push_back(vector<int>(x, x + 2));
        }

        return ans;
    }
    int mean(priority_queue<int, vector<int>, greater<int> >& q) {
    	int sum = 0;
    	while (!q.empty()) {
    		sum += q.top();
    		q.pop();
    	}
    	return sum / 5;
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