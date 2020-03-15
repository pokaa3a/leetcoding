#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

class Solution {
public:
	vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
		map<int, int> count;
		for (int i = 0; i < arr1.size(); ++i) {
			count[arr1[i]]++;
		}

		vector<int> res;
		for (int i = 0; i < arr2.size(); ++i) {
			int cnt = count[arr2[i]];
			for (int j = 0; j < cnt; ++j) {
				res.push_back(arr2[i]);
			}
			count.erase(arr2[i]);
		}

		for (map<int, int>::iterator it = count.begin(); it != count.end(); ++it) {
			int cnt = it->second;
			for (int j = 0; j < cnt; ++j) {
				res.push_back(it->first);
			}
		}
		return res;
	}
};

int main() {
	int a1[] = {2,3,1,3,2,4,6,7,9,2,19};
	int a2[] = {2,1,4,3,9,6};

	vector<int> arr1(a1, a1 + 11);
	vector<int> arr2(a2, a2 + 6);

	Solution sol;
	vector<int> res = sol.relativeSortArray(arr1, arr2);
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << " ";
	}
	cout << endl;
}