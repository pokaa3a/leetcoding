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
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        int n = words.size(), m = puzzles.size();
        vector<int> ans(m, 0);

        vector<int> word_pattern((1 << 26), 0);
        for (int i = 0; i < n; ++i) {
        	int mask = 0;
        	string word = words[i];
        	for (int j = 0; j < word.size(); ++j) {
        		mask |= (1 << (word[j] - 'a'));
        	}
        	word_pattern[mask]++;
        }

        for (int i = 0; i < m; ++i) {
        	string puzzle = puzzles[i];
        	int len = puzzle.size();
        	for (int j = 0; j < (1 << (len - 1)); ++j) {
        		int mask = (1 << (puzzle[0] - 'a'));
        		for (int k = 0; k < len - 1; ++k) {
        			if (j & (1 << k)) {
        				mask |= (1 << (puzzle[k + 1] - 'a'));
        			}
        		}
        		ans[i] += word_pattern[mask];
        	}
        }
        return ans;
    }
};

int main() {
  // Solution
  Solution sol;

  // Test cases
  string words_arr[] = {"aaaa","asas","able","ability","actt","actor","access"};
  vector<string> words(words_arr, words_arr + 7);

  string puzzles_arr[] = {"aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"};
  vector<string> puzzles(puzzles_arr, puzzles_arr + 6);

  vector<int> ans = sol.findNumOfValidWords(words, puzzles);
  for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
  cout << endl;

}