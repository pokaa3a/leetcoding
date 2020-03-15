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
    int longestStrChain(vector<string>& words) {
        unordered_set<string> words_set(words.begin(), words.end());

        unordered_map<string, vector<string> > graph;
        for (int i = 0; i < words.size(); ++i) {
        	string word = words[i];
        	int len = word.size();
        	if (len == 1) continue;
        	for (int i = 0; i < len; ++i) {
        		string sub = word.substr(0, i) + word.substr(i + 1);
        		if (words_set.find(sub) != words_set.end()) {
        			graph[word].push_back(sub);
        		}
        	}
        }

        unordered_map<string, int> depth;
        int ans = 0;
        for (int i = 0; i < words.size(); ++i) {
        	ans = max(ans, dfs(words[i], graph, depth));
        }
        return ans;
    }
   	int dfs(string word, unordered_map<string, vector<string> >& graph, unordered_map<string, int>& depth) {
   		if (depth.find(word) != depth.end()) return depth[word];

   		int ans = 1;
   		for (int i = 0; i < graph[word].size(); ++i) {
   			ans = max(ans, dfs(graph[word][i], graph, depth) + 1);
   		}
   		depth[word] = ans;
   		return ans;
   	}
};

int main() {
	// Solution
	Solution sol;

	// Test cases
	string w[] = {"a","b","ba","bca","bda","bdca"};
	vector<string> words(w, w + 6);
	cout << sol.longestStrChain(words) << endl;
}