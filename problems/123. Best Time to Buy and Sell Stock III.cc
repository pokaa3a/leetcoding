#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
	int maxProfit(vector<int> &prices){
		if(prices.size() <= 1) return 0;
		int K = 2;
		vector<vector<int> > max_profits(K+1, vector<int>(prices.size(), 0));
		int maxProf = 0;
		for(int k = 1; k <= K; ++k){
			int tmpMax = -prices[0];
			for(int i = 1; i<prices.size(); ++i){
				max_profits[k][i] = max(max_profits[k][i-1], prices[i] + tmpMax);
				tmpMax = max(tmpMax, max_profits[k-1][i-1] - prices[i]);
				maxProf = max(maxProf, max_profits[k][i]);
			}
		}
		return maxProf;
	}
};

int main(){
	int array[] = {0,2,0,4,2,5};
	vector<int> prices(array, array+6);

	Solution sol;
	cout << "Max Profit: " << sol.maxProfit(prices);
}