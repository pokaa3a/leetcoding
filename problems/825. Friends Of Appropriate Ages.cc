#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	int numFriendRequests(vector<int>& ages) {
		sort(ages.begin(), ages.end());
		cout << "ages: ";
		for (int i = 0; i < ages.size(); ++i) {
			cout << ages[i] << " ";
		}
		map<int, int> ageMap;
		int preIdx = ages.size()-2;
		int numFriends = 0;
		cout << endl;
		for (int i = ages.size()-1; i >= 0; --i) {
			cout << "person with age " << ages[i];
			int numRequests = 0;
			if (ageMap.count(ages[i]) > 0) {
				numRequests = ageMap[ages[i]];
				
			} else {
				int idxFriend = ageHelper(ages, 0, min(preIdx, i - 1), double(ages[i]) * 0.5 + 7);
				preIdx = idxFriend;
				numRequests = i - idxFriend;
				ageMap[ages[i]] = numRequests;
			}
			cout << " can friend (>" << double(ages[i]) * 0.5 + 7 << ") " << numRequests << " people" << endl;
			numFriends += numRequests;
		}
		return numFriends;
	}

	int ageHelper(vector<int>& ages, int left, int right, double threshold) {
		while (left <= right) {
			int mid = (left + right) / 2;
			if (mid > 0 && ages[mid-1] > threshold) {
				right = mid - 1;
			} else if (ages[mid] <= threshold) {
				left = mid + 1;
			} else {
				return mid;
			}
		}
		return left;
	}
};

int main(){
	int array[] = {53,109,24,35,22,37,58,99,26,70,22,81,30,36,69};
	vector<int> ages(array, array+15);
	Solution sol;
	cout << sol.numFriendRequests(ages);
}