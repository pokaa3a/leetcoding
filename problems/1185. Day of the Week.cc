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
    string dayOfTheWeek(int day, int month, int year) {
        switch (day_after_1_1_1971(day, month, year) % 7) {
        	case 0:
        		return "Friday"; 
        	case 1:
        		return "Saturday";
        	case 2:
        		return "Sunday";
        	case 3:
        		return "Monday";
        	case 4:
        		return "Tuesday";
        	case 5:
        		return "Wednesday";
        	case 6:
        		return "Thursday";
        }
        return "";
    }
    int day_after_1_1_1971(int d, int m, int y) {
    	int days = d;
    	for (int i = 0; i + 1971 < y; ++i) {
    		days += isLeap(1971 + i) ? 366 : 365;
    	}
    	for (int i = 0; i + 1 < m; ++i) {
    		if (i + 1 == 2) {
    			days += isLeap(y) ? 29 : 28;
    		} else {
    			if (i + 1 > 7) {
    				days += (i + 1) % 2 == 0 ? 31 : 30;
    			} else {
    				days += (i + 1) % 2 == 1 ? 31 : 30;
    			}
    		}
    	}
    	return days - 1;
    }
    bool isLeap(int y) {
    	if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0)) return true;
    	return false;
    }
};

int main() {
	/* Solution */
	Solution sol;

	cout << sol.dayOfTheWeek(31, 8, 2019) << endl;
	cout << sol.dayOfTheWeek(18, 7, 1999) << endl;
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