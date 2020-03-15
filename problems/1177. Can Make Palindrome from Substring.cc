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
// class Solution {
// public:
//     vector<bool> canMakePaliQueries(string s, vector<vector<int> >& queries) {
//         vector<bool> ans(queries.size(), false);
//         int n = s.size();
//         vector<vector<int> > sums(26, vector<int>(n + 1, 0));

//         for (int i = 0; i < 26; ++i) {
//         	for (int j = 1; j < n + 1; ++j) {
//         		char c = s[j - 1];
//         		sums[i][j] = sums[i][j - 1] + (c - 'a' == i ? 1 : 0);
//         	}
//         }

//         for (int i = 0; i < queries.size(); ++i) {
//         	int lft = queries[i][0];
//         	int rht = queries[i][1];
//         	int k = queries[i][2];

//         	int num_odd = 0;
//         	for (int j = 0; j < 26; ++j) {
//         		int count = sums[j][rht + 1] - sums[j][lft];
//         		if (count % 2 == 1) num_odd++;
//         	}
//         	// cout << "i: " << i << endl;
//         	// cout << "lft: " << lft << " rht: " << rht << " k: " << k << endl;
//         	// cout << "num_odd: " << num_odd << endl;

//         	if (num_odd / 2 <= k) ans[i] = true;
//         	// if ((rht - lft + 1) % 2 == 0) {
//         	// 	if (num_odd <= k) ans[i] = true;
//         	// } else {
//         	// 	if (num_odd - 1 <= k) ans[i] = true;
//         	// }
//         }
//         return ans;
//     }
// };
class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int> >& queries) {
        vector<vector<int> > char_sums(s.size(), vector<int>(26, 0));
        char_sums[0][s[0] - 'a'] = 1;
        for (int i = 1; i < s.size(); ++i) {
            for (int j = 0; j < 26; ++j) {
                char_sums[i][j] = char_sums[i - 1][j];
            }
            char_sums[i][s[i] - 'a']++;
        }
        vector<bool> ans(queries.size(), false);
        for (int i = 0; i < queries.size(); ++i) {
            int lft = queries[i][0];
            int rht = queries[i][1];
            int k = queries[i][2];
            ans[i] = can_be_palindrome(lft, rht, k, char_sums);
        }
        return ans;
    }
    bool can_be_palindrome(int left, int right, int k, vector<vector<int> >& char_sums) {
        int n_odd = 0;
        for (int i = 0; i < 26; ++i) {
            int n = char_sums[right][i] - (left - 1 < 0 ? 0 : char_sums[left - 1][i]);
            if (n % 2 == 1) n_odd++;
        }
        return k >= (n_odd / 2);
    }
};


int main() {
  // Solution
  Solution sol;

  // Test cases
  string s = "abcda";
  int q[5][3] = {{3,3,0}, {1,2,0}, {0,3,1}, {0,3,2}, {0,4,1}};
  vector<vector<int> > queries;
  for (int i = 0; i < 5; i++) {
  		queries.push_back(vector<int>(q[i], q[i] + 3));
  }
  vector<bool> ans = sol.canMakePaliQueries(s, queries);
  for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
  cout << endl;
}