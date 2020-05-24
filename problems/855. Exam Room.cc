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
class ExamRoom {
public:
	set<int> sitted;
	priority_queue<pair<int, int>> pq;
    int n;
    ExamRoom(int N) {
        n = N;
        sitted.insert(-1);
        sitted.insert(n);
        pq.push(make_pair(n + 1, -(-1)));
    }
    
    int seat() {
        set<int>::iterator left_it, right_it;
        int left_id, right_id;
        while (!pq.empty()) {
        	left_id = -pq.top().second;
        	left_it = sitted.find(left_id);
        	right_it = next(left_it);
        	right_id = *right_it;

        	if (possible_dist(left_id, right_id) == pq.top().first) {
        		pq.pop();
        		break;
        	}
        	pq.pop();
        }

        int new_id = possible_id(left_id, right_id);
        sitted.insert(new_id);
        pq.push(make_pair(possible_dist(left_id, new_id), -left_id));
        pq.push(make_pair(possible_dist(new_id, right_id), -new_id));

        // cout << "seat: " << new_id << endl;
        // cout << "left_dist: " << left_dist << " right_dist: " << right_dist << endl;
        // for (int x : sitted) {
        // 	cout << x << " ";
        // }
        // cout << endl;

        return new_id;
    }
    
    void leave(int p) {
        auto it = sitted.find(p);
        auto left_it = prev(it);
        auto right_it = next(it);

        int left_id = *left_it;
        int right_id = *right_it;

        pq.push(make_pair(possible_dist(left_id, right_id), -left_id));
        sitted.erase(p);

        // cout << "leave: " << p << endl;
        // for (int x : sitted) {
        // 	cout << x << " ";
        // }
        // cout << endl;
    }
    int possible_dist(int i1, int i2) {
    	if (i1 == -1) {				// will insert 0
    		return i2;
    	} else if (i2 == n) {		// will insert n - 1
    		return (n - 1) - i1;
    	}
    	return (i1 + i2) / 2 - i1;
    }
    int possible_id(int i1, int i2) {
    	if (i1 == -1) return 0;
    	if (i2 == n) return n - 1;
    	return (i1 + i2) / 2;
    }
};

int main() {
	/* Solution */

	/* Test cases */
	ExamRoom *er = new ExamRoom(4);

	er->seat();
	er->seat();
	er->seat();
	er->seat();
	er->leave(1);
	er->leave(3);
	er->seat();

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