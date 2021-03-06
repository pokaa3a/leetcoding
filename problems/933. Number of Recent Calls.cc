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

/* Solution */
const int MOD = 1000000007;
class RecentCounter {
	queue<int> calls;
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        calls.push(t);
        while (calls.front() < t - 3000) {
        	calls.pop();
        }
        return calls.size();
    }
};


int main() {
	/* Solution */
	RecentCounter sol;

	/* Test cases */
	cout << sol.ping(1) << endl;
	cout << sol.ping(100) << endl;
	cout << sol.ping(3001) << endl;
	cout << sol.ping(3002) << endl;

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