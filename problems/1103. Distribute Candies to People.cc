#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> ans(num_people, 0);
        int round = 0;
        while (candies > 0) {
        	for (int i = 0; i < num_people; ++i) {
        		int to_give = candies >= (num_people * round + i + 1) ? (num_people * round + i + 1) : candies;
        		ans[i] += to_give;
        		candies -= to_give;
        		if (candies == 0) return ans;
        	}
        	round++;
        }
        return ans;
    }
};

int main() {
	int candies = 10;
	int num_people = 3;
	Solution sol;
	vector<int> res = sol.distributeCandies(candies, num_people);
	for (int i = 0; i < res.size(); ++i) cout << res[i] << " ";
	cout << endl;
}