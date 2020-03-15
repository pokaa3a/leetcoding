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

const int MOD = 1000000007;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* Solution */
class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        double mini = 256, maxi = 0, mode = 0, mode_n = 0, total = 0;
        vector<int> sums_count(count.size(), 0);
        for (int i = 0; i < count.size(); ++i) {
        	sums_count[i] = (i - 1 < 0 ? 0 : sums_count[i - 1]) + count[i];
        	if (count[i] > 0) {
        		mini = min(mini, (double)i);
        		maxi = max(maxi, (double)i);
        		if (count[i] > mode_n) {
        			mode_n = count[i];
        			mode = (double)i;
        		}
        	}
        	total += count[i] * i;
        }
        double mean = total / double(sums_count.back());
        double median = 0;
        if (sums_count.back() % 2 == 0) {
        	int med_id_1 = lower_bound(sums_count.begin(), sums_count.end(), (sums_count.back() - 1) / 2 + 1) - sums_count.begin();
        	int med_id_2 = lower_bound(sums_count.begin(), sums_count.end(), sums_count.back() / 2 + 1) - sums_count.begin();
        	median = (double(med_id_1) + double(med_id_2)) / 2;
        } else {
        	int med_id = lower_bound(sums_count.begin(), sums_count.end(), sums_count.back() / 2 + 1) - sums_count.begin();
        	median = double(med_id);
        }
    	double a[] = {mini, maxi, mean, median, mode};
    	return vector<double>(a, a + 5);
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases
	int c[] = {0,4,3,2,2,0,0};
	vector<int> count(c, c + 7);
	vector<double> ans = sol.sampleStats(count);
	for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
	cout << endl;
}