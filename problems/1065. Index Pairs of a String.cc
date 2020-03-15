#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <queue>
#include <stack>
#include <sstream>
#include <cmath>
using namespace std;

const int MOD = 1000000007;

/* Solution */
class Solution {
public:
    vector<vector<int> > indexPairs(string text, vector<string>& words) {
        vector<vector<int> > ans;
        for (int i = 0; i < words.size(); ++i) {
        	int found = text.find(words[i]);
        	while (found != string::npos) {
        		int p[] = {found, found + words[i].size() - 1};
        		ans.push_back(vector<int>(p, p + 2));
        		found = text.find(words[i], found + 1);
        	}
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
  // Solution
  Solution sol;

  // Test cases
  string text = "ababa";
  string s[] = {"aba","ab"};
  vector<string> words(s, s + 2);
  vector<vector<int> > ans = sol.indexPairs(text, words);
  for (int i = 0; i < ans.size(); ++i) {
  	cout << ans[i][0] << ", " << ans[i][1] << endl;
  }
  cout << endl;
}