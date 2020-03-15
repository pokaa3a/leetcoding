#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	bool isNStraightHand(vector<int>& hand, int W) {
		if (hand.size() % W != 0) return false;
		map<int, int> count;
		for (int i = 0; i < hand.size(); ++i) {
			count[hand[i]]++;
		}
		while (count.size()) {
			int h = count.begin()->first;
			for (int i = 0; i < W; ++i) {
				if (count.find(h + i) == count.end()) return false;
				if (--count[h + i] == 0) count.erase(h + i);
			}
		}
		return true;
	}
};

int main() {
	int h[] = {1,2,3,6,2,3,4,7,8};
	vector<int> hand(h, h + 9);
	int W = 3;
	Solution sol;
	cout << sol.isNStraightHand(hand, W) << endl;
}