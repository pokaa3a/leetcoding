#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int totalFruit(vector<int> &tree) {
		if (tree.size() <= 2) return tree.size();

		int p = 0, e1 = -1, e2 = -1, ans = 2;
		while (p < tree.size()) {
			int h1 = min(e1, e2) + 1;
			int fruit1 = tree[h1];
			int h2 = h1 + 1;
			while (h2 < tree.size() && tree[h2] == fruit1) {
				h2++;
			}
			if (h2 < tree.size()) {
				e1 = h2 - 1;
				e2 = h2;
			} else {
				ans = max(ans, h2 - h1);
				break;
			}
			ans = max(ans, h2 - h1 + 1);
			p = e2 + 1;
			int fruit2 = tree[h2];

			while (p < tree.size() && (tree[p] == fruit1 || tree[p] == fruit2)) {
				e1 = tree[p] == fruit1 ? p : e1;
				e2 = tree[p] == fruit2 ? p : e2;
				ans = max(ans, max(e1, e2) - h1 + 1);
				p++;
			}
		}
		return ans;
	}
};

int main() {
	int array[] = {0};
	vector<int> tree(array, array + 1);
	Solution sol;
	cout << sol.totalFruit(tree) << endl;
}