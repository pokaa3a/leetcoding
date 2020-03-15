#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
	int removeStones(vector<vector<int> >& stones) {
		unordered_map<int, vector<int> > row_map;
		unordered_map<int, vector<int> > col_map;
		vector<int> data;
		for (int i = 0; i < stones.size(); ++i) {
			row_map[stones[i][0]].push_back(i);
			col_map[stones[i][1]].push_back(i);
			data.push_back(i);
		}

		for (int i = 0; i < stones.size(); ++i) {
			for (int j = 0; j < row_map[stones[i][0]].size(); ++j) {
				unite(data, i, row_map[stones[i][0]][j]);
			}
			for (int j = 0; j < col_map[stones[i][1]].size(); ++j) {
				unite(data, i, col_map[stones[i][1]][j]);
			}
		}
		unordered_set<int> unique;
		for (int i = 0; i < data.size(); ++i) {
			unique.insert(find(data, i));
		}
		return stones.size() - unique.size();
	}
private:
	int find(vector<int>& data, int i) {
		if (i != data[i]) {
			data[i] = find(data, data[i]);
		}
		return data[i];
	}
	void unite(vector<int>& data, int i, int j) {
		int pi = find(data, i);
		int pj = find(data, j);
		if (pi != pj) {
			data[pi] = pj;
		}
	}
};

int main() {
	vector<vector<int> > stones;

	int st1[] = {0, 0};
	stones.push_back(vector<int>(st1, st1 + 2));
	int st2[] = {0, 1};
	stones.push_back(vector<int>(st2, st2 + 2));
	int st3[] = {1, 0};
	stones.push_back(vector<int>(st3, st3 + 2));
	int st4[] = {1, 2};
	stones.push_back(vector<int>(st4, st4 + 2));
	int st5[] = {2, 1};
	stones.push_back(vector<int>(st5, st5 + 2));
	int st6[] = {2, 2};
	stones.push_back(vector<int>(st6, st6 + 2));

	Solution sol;
	cout << sol.removeStones(stones) << endl;

}
