#include <iostream>
#include <vector>
using namespace std;

// class Solution {
// public:
// 	int maxProfit(vector<int>& prices) {
// 		if (!prices.size()) return 0;

// 		vector<int> buy(1, -prices[0]);
// 		vector<int> sell(1, INT_MIN);
// 		vector<int> rest_s(1, INT_MIN);
// 		vector<int> rest_n(1, 0);
// 		for (int i = 1; i < prices.size(); ++i) {
// 			buy.push_back(rest_n[i - 1] - prices[i]);
// 			sell.push_back(max(buy[i - 1] + prices[i], rest_s[i - 1] + prices[i]));
// 			rest_s.push_back(max(rest_s[i - 1], buy[i - 1]));
// 			rest_n.push_back(max(rest_n[i - 1], sell[i - 1]));
// 		}
// 		int n = prices.size() - 1;
// 		return max(max(buy[n], sell[n]), max(rest_s[n], rest_n[n]));
// 	}
// };
class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	if (prices.empty()) return 0;
        // define state:
        // dp1[i] : best profit from first i days and holding a stock
        // dp2[i] : best profit from first i days and NOT holding a stock
    	int n = prices.size();
        vector<int> dp1(n + 1, 0), dp2(n + 1, 0);

        // define initial state
        dp1[1] = -prices[0];
        dp2[1] = 0;

        // fill dp tables
        for (int i = 2; i <= n; ++i) {
        	dp1[i] = max(dp1[i - 1], dp2[i - 2] - prices[i - 1]);
        	dp2[i] = max(dp2[i - 1], dp1[i - 1] + prices[i - 1]);
        }
        return max(dp1[n], dp2[n]);
    }
};

int main() {
	int array[] = {1, 2, 3, 0, 2};
	vector<int> prices(array, array+5);
	Solution sol;
	cout << sol.maxProfit(prices) << endl;
}