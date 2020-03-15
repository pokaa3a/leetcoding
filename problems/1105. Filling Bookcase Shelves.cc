#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minHeightShelves(vector<vector<int> >& books, int shelf_width) {
        int res = 0, n = books.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int len = 1; len <= n; ++len) {
        	int cur_wid = 0, max_h = 0;
        	for (int i = len - 1; i >= 0; --i) {
        		cur_wid += books[i][0];
        		if (cur_wid <= shelf_width) {
        			max_h = max(max_h, books[i][1]);
        			dp[len] = min(dp[len], dp[i] + max_h);
        		} else break;
        	}
        }
        return dp[n];
    }
};

int main() {
	const int n_books = 4;
	int b[n_books][2] = {{7,3}, {8,7}, {2,7}, {2,5}};
	vector<vector<int> > books;
	for (int i = 0; i < n_books; ++i) {
		books.push_back(vector<int>(b[i], b[i] + 2));
	}
	int shelf_width = 10;
	Solution sol;
	cout << sol.minHeightShelves(books, shelf_width) << endl;
}