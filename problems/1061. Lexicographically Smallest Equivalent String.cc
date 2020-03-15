#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string smallestEquivalentString(string A, string B, string S) {
        int n = A.size();
        group.resize(26, 0);
        for (int i = 0; i < 26; ++i) group[i] = i;

        for (int i = 0; i < n; ++i) {
        	int x = (A[i] - 'a') < (B[i] - 'a') ? (A[i] - 'a') : (B[i] - 'a');
        	int y = (A[i] - 'a') > (B[i] - 'a') ? (A[i] - 'a') : (B[i] - 'a');
        	int g_x = find(x);
        	int g_y = find(y);
        	if (g_x != g_y) {
        		group[g_x] = min(g_x, g_y);
				group[g_y] = min(g_x, g_y);
        	}
        }

        string ans;
        for (int i = 0; i < S.size(); ++i) {
        	int x = find(S[i] - 'a');
        	ans += char(x + 'a');
        }
        return ans;
    }
private:
	vector<int> group;
	int find(int x) {
		if (x != group[x]) group[x] = find(group[x]);
		return group[x];
	}
};

int main() {
	string A = "leetcode";
	string B = "programs";
	string S = "sourcecode";
	Solution sol;
	cout << sol.smallestEquivalentString(A, B, S) << endl;
}