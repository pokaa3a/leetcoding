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
class UndergroundSystem {
public:
	unordered_map<int, pair<string, int> > customers;
	unordered_map<string, int> travel_time;
	unordered_map<string, int> travel_counts;

    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        customers[id] = make_pair(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
        pair<string, int> c = customers[id];
        string enter_station = c.first;
        int enter_time = c.second;
        customers.erase(id);

        string travel = enter_station + stationName;
        travel_time[travel] += t - enter_time;
        travel_counts[travel]++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string travel = startStation + endStation;
        // cout << "travle time: " << travel_time[travel] << endl;
        // cout << "travel counts: " << travel_counts[travel] << endl; 
        return (double)travel_time[travel] / (double)travel_counts[travel];
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