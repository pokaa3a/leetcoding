#include <iostream>
#include <vector>
using namespace std;

// class Solution {
// public:
// 	void duplicateZeros(vector<int>& arr) {
// 		int n = arr.size();
// 		for (int i = 0; i < n; ++i) {
// 			if (arr[i] == 0) dup(arr, i++);
// 		}
// 	}
// private:
// 	void dup(vector<int>& arr, int idx) {
// 		int n = arr.size();
// 		int prev = arr[idx], buf;
// 		for (int i = idx + 1; i < n; ++i) {
// 			buf = arr[i];
// 			arr[i] = prev;
// 			prev = buf;
// 		}
// 	}
// };

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        vector<int> dup(arr.begin(), arr.end());
        int j = 0;
        for (int i = 0; i < dup.size(); ++i) {
            if (dup[i] == 0) {
                for (int k = 0; k < 2; ++k){
                    arr[j] = 0;
                    j++;
                    if (j >= arr.size()) return;
                }
            } else {
                arr[j] = dup[i];
                j++;
                if (j >= arr.size()) return;
            }
        }
    }
};


int main() {
	int a[] = {1,2,0,3,0,5};
	vector<int> arr(a, a + 6);
	Solution sol;
	sol.duplicateZeros(arr);

	for (int i = 0; i < arr.size(); ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
}