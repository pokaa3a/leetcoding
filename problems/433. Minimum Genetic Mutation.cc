#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>

using namespace std;

class Solution {
public:
	int minMutation(string start, string end, vector<string> &bank) {
		char array[] = {'A', 'C', 'G', 'T'};
		vector<char> gene(array, array + 4);

		// Convert vector to set
		set<string> bank_set;
		for (int i = 0; i < bank.size(); ++i) {
			bank_set.insert(bank[i]);
		}
		if (!bank_set.count(end)) return -1;

		// BFS
		set<string> visited;
		queue<string> q;
		q.push(start);

		int num_mutations = 0;
		while (!q.empty()) {
			int q_size = q.size();
			for (int i = 0; i < q_size; ++i) {
				string s = q.front();
				q.pop();
				for (int k = 0; k < start.length(); ++k) {
					char original_gene = s[k];
					for (int g = 0; g < gene.size(); g++){
						if (gene[g] == original_gene) continue;
						s[k] = gene[g];
						if (s == end) return num_mutations + 1;
						if (bank_set.count(s) && !visited.count(s)) {
							q.push(s);
							visited.insert(s);
						}
						s[k] = original_gene;
					}
				}
			}
			num_mutations++;
		}
		return -1;
	}
};

int main() {
	string start = "AAAAC";
	string end = "CCCCC";
	vector<string> bank;
	bank.push_back("AAAAA");
	bank.push_back("AAACA");
	bank.push_back("AACCA");
	bank.push_back("AACCC");
	bank.push_back("ACCCC");
	bank.push_back("CCCCC");
	bank.push_back("AAACC");
	bank.push_back("AACCC");

	Solution sol;
	cout << sol.minMutation(start, end, bank) << endl;
}