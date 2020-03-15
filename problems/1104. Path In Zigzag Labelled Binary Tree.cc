#include <iostream>
#include <vector>
using namespace std;

// class Solution {
// public:
//     vector<int> pathInZigZagTree(int label) {
//     	vector<int> res;
//     	int true_label = convert(label);
//     	while (true_label > 0) {
//     		res.push_back(convert(true_label));
//     		true_label /= 2;
//     	}
//     	reverse(res.begin(), res.end());
//     	return res;
//     }
// 	int convert(int x) {
// 		if (x == 1) return 1;

// 		int k = 0;
// 		while ((1 << k) <= x) k++;
// 		int low_bnd = (1 << (k - 1));
// 		int upp_bnd = (1 << k) - 1;
// 		if (k % 2 == 0) return low_bnd + upp_bnd - x;
// 		else return x;
// 	}
// };

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int x = change(label);
        vector<int> ans;
        while (x > 0) {
            ans.push_back(change(x));
            x = x >> 1;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    int log_two(int x) {
        int k = 0;
        while (x > 0) {
            x = x >> 1;
            k++;
        }
        return k - 1;
    }
    int change(int x) {
        int ans;
        int k = log_two(x);
        if (k % 2 != 0) {
            ans = (1 << k) + (1 << (k + 1)) - 1 - x;
        } else {
            ans = x;
        }
        return ans;
    }
};

int main() {
	int label = 26;
	Solution sol;
	vector<int> res = sol.pathInZigZagTree(label);
	for (int i = 0; i < res.size(); ++i) cout << res[i] << " ";
	cout << endl;
}