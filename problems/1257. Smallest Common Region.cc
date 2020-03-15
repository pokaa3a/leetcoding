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
// struct Region {
// 	string name;
// 	Region* parent;
// 	Region(string r, Region* p) : name(r), parent(p) {}
// };
// class Solution {
// public:
//     string findSmallestRegion(vector<vector<string> >& regions, string region1, string region2) {
//         map<string, Region*> m;
//         for (int i = 0; i < regions.size(); ++i) {
//         	if (m.find(regions[i][0]) == m.end()) {
//         		Region* parent_region = new Region(regions[i][0], NULL);
//         		m[regions[i][0]] = parent_region;
//         	}
//         	for (int j = 1; j < regions[i].size(); ++j) {
//         		if (m.find(regions[i][j]) == m.end()) {
//         			Region* child_region = new Region(regions[i][j], m[regions[i][0]]);
//         			m[regions[i][j]] = child_region;
//         		} else {
//         			Region* child_region = m[regions[i][j]];
//         			child_region->parent = m[regions[i][0]];
//         		}
//         	}
//         }
//         Region* r1 = m[region1];
//         Region* r2 = m[region2];
//         set<string> r1_parents, r2_parents;
//         while (r1 != NULL || r2 != NULL) {
//         	if (r1) {
//         		r1_parents.insert(r1->name);
//         		if (r2_parents.count(r1->name)) return r1->name;
//         		r1 = r1->parent;
//         	}
//         	if (r2) {
//         		r2_parents.insert(r2->name);
//         		if (r1_parents.count(r2->name)) return r2->name;
//         		r2 = r2->parent;
//         	}
//         }
//         return "";
//     }
// };
class Solution {
public:
    string findSmallestRegion(vector<vector<string> >& regions, string region1, string region2) {
        map<string, string> parents;
        for (int i = 0; i < regions.size(); ++i) {
        	for (int j = 1; j < regions[i].size(); ++j) {
        		parents[regions[i][j]] = regions[i][0];
        	}
        }
        string r1 = region1, r2 = region2;
        set<string> r1_parents, r2_parents;
        
        while (true) {
            r1_parents.insert(r1);
            r2_parents.insert(r2);
        	if (r2_parents.count(r1)) return r1;
        	if (r1_parents.count(r2)) return r2;
        	r1 = parents.find(r1) == parents.end() ? "" : parents[r1];
        	r2 = parents.find(r2) == parents.end() ? "" : parents[r2];
        }
        return "";
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	string r1[] = {"Earth","North America","South America"};
	string r2[] = {"North America","United States","Canada"};
	string r3[] = {"United States","New York","Boston"};
	string r4[] = {"Canada","Ontario","Quebec"};
	string r5[] = {"South America","Brazil"};
	vector<vector<string> > regions;
	regions.push_back(vector<string>(r1, r1 + 5));
	regions.push_back(vector<string>(r2, r2 + 5));
	regions.push_back(vector<string>(r3, r3 + 3));
	regions.push_back(vector<string>(r4, r4 + 3));
	regions.push_back(vector<string>(r5, r5 + 2));

	string region1 = "Quebec", region2 = "New York";
	cout << sol.findSmallestRegion(regions, region1, region2) << endl;

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