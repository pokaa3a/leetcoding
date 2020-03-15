#include <iostream>
#include <vector>
using namespace std;

class MountainArray {
public:
	int get(int index) {
		if (index >= arr.size() ||
			index < 0) return -1;
		return arr[index];
	}

	int length() {
		return arr.size();
	}

	MountainArray(vector<int>& a) {
		arr = a;
	}

private:
	vector<int> arr;
};

class Solution {
public:
	int findInMountainArray(int target, MountainArray &mountainArr) {
		int n = mountainArr.length();
		int left = 0, right = n - 2;
		while (left < right) {
			int mid = (left + right) / 2;
			if (mountainArr.get(mid) > mountainArr.get(mid + 1)) {
				right = mid;
			} else {
				left = mid + 1;
			}
		}
		int peak = left;

		// b-search - left
		left = 0;
		right = peak;
		while (left < right) {
			int mid = (left + right) / 2;
			if (mountainArr.get(mid) < target) {
				left = mid + 1;
			} else if (mountainArr.get(mid) > target) {
				right = mid;
			} else {
				return mid;
			}
		}
		if (mountainArr.get(left) == target) return left;

		// b-search - right
		left = peak;
		right = n - 1;
		while (left < right) {
			int mid = (left + right) / 2;
			cout << "mid: " << mid << endl;
			if (mountainArr.get(mid) < target) {
				right = mid;
			} else if (mountainArr.get(mid) > target) {
				left = mid + 1;
			} else {
				return mid;
			}
		}
		if (mountainArr.get(left) == target) return left;
		return -1;
	}
};

int main() {
	int a[] = {1,5,2};
	vector<int> arr(a, a + 3);
	int target = 2;
	MountainArray mountainArray(arr);
	Solution sol;
	cout << sol.findInMountainArray(target, mountainArray) << endl;
}