#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int> >& dominoes) {
        map<pair<int, int>, int> mp;
        for (int i = 0; i < dominoes.size(); ++i) {
        	int x = min(dominoes[i][0], dominoes[i][1]);
        	int y = max(dominoes[i][0], dominoes[i][1]);
        	mp[make_pair(x, y)]++;
        }
        int res = 0;
        for (map<pair<int, int>, int>::iterator it = mp.begin(); it != mp.end(); ++it) {
        	res += (it->second) * (it->second - 1) / 2;
        }
        return res;
    }
};

int main() {
	int p1[] = {1, 2};
	int p2[] = {1, 2};
	int p3[] = {1, 1};
	int p4[] = {1, 2};
	vector<vector<int> > dominoes;
	dominoes.push_back(vector<int>(p1, p1 + 2));
	dominoes.push_back(vector<int>(p2, p2 + 2));
	dominoes.push_back(vector<int>(p3, p3 + 2));
	dominoes.push_back(vector<int>(p4, p4 + 2));
	Solution sol;
	cout << sol.numEquivDominoPairs(dominoes) << endl;
}