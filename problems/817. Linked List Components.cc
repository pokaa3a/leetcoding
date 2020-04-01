#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	int numComponents(ListNode* head, vector<int>& G) {
		int n = G.size();
		unordered_map<int, int> val2idx;
		vector<int> group(n, 0);
		for (int i = 0; i < n; i++) {
			group[i] = i;
			val2idx[G[i]] = i;
		}

		ListNode* cur = head;
		while (cur->next) {
			if (val2idx.find(cur->val) != val2idx.end() &&
				val2idx.find(cur->next->val) != val2idx.end()) {
				int idx1 = val2idx[cur->val], idx2 = val2idx[cur->next->val];
				uni(idx1, idx2, group);
			}
			cur = cur->next;
		}
		unordered_set<int> unique;
		for (int i = 0; i < n; i++) {
			int a = find(i, group);
			unique.insert(a);
		}
		return unique.size();
	}
	int find(int x, vector<int>& group) {
		if (x != group[x]) group[x] = find(group[x], group);
		return group[x];
	}
	void uni(int x, int y, vector<int>& group) {
		int a = find(x, group);
		int b = find(y, group);
		if (a != b) group[a] = b;
	}
};

int main() {
	ListNode* head = new ListNode(0);
	ListNode* cur = head;
	for (int i = 1; i <= 4; i++) {
		cur->next = new ListNode(i);
		cur = cur->next;
	}
	vector<int> G = {0, 1, 3, 4};

	Solution sol;
	cout << sol.numComponents(head, G) << endl;
}