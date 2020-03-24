#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// class Solution {
// public:
// 	int totalFruit(vector<int> &tree) {
// 		if (tree.size() <= 2) return tree.size();

// 		int p = 0, e1 = -1, e2 = -1, ans = 2;
// 		while (p < tree.size()) {
// 			int h1 = min(e1, e2) + 1;
// 			int fruit1 = tree[h1];
// 			int h2 = h1 + 1;
// 			while (h2 < tree.size() && tree[h2] == fruit1) {
// 				h2++;
// 			}
// 			if (h2 < tree.size()) {
// 				e1 = h2 - 1;
// 				e2 = h2;
// 			} else {
// 				ans = max(ans, h2 - h1);
// 				break;
// 			}
// 			ans = max(ans, h2 - h1 + 1);
// 			p = e2 + 1;
// 			int fruit2 = tree[h2];

// 			while (p < tree.size() && (tree[p] == fruit1 || tree[p] == fruit2)) {
// 				e1 = tree[p] == fruit1 ? p : e1;
// 				e2 = tree[p] == fruit2 ? p : e2;
// 				ans = max(ans, max(e1, e2) - h1 + 1);
// 				p++;
// 			}
// 		}
// 		return ans;
// 	}
// };

class Solution {
public:
	int totalFruit(vector<int>& tree) {
		int fruit1 = -1, fruit2 = -1, cont1 = 0, cont2 = 0, cont_cur = 0, ans = 0;
		for (int i = tree.size() - 1; i >= 0; i--) {
			if (tree[i] == fruit1) {
				cont_cur++;
				cont1++;
			} else if (tree[i] == fruit2) {
				cont2++;
				swap(fruit1, fruit2);
				swap(cont1, cont2);
				cont_cur = 1;
			} else {
				fruit2 = fruit1;
				fruit1 = tree[i];
				cont2 = cont_cur;
				cont1 = 1;
				cont_cur = 1;
			}
			// cout << "i: " << i << " total: " << cont1 + cont2 << endl;
			// cout << "fruit1: " << fruit1 << ", fruit2: " << fruit2 << endl;
			ans = max(ans, cont1 + cont2);
		}
		return ans;
	}
};

int main() {
	int array[] = {3,3,3,1,2,1,1,2,3,3,4};
	vector<int> tree(array, array + sizeof(array) / sizeof(int));
	Solution sol;
	cout << sol.totalFruit(tree) << endl;
}