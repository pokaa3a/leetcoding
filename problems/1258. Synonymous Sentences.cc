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

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

/* Solution */
const int MOD = 1000000007;
class Solution {
public:
    vector<string> generateSentences(vector<vector<string> >& synonyms, string text) {
        stringstream ss(text);
        string token;
        vector<string> vec_text;
        while (getline(ss, token, ' ')) {
        	vec_text.push_back(token);
        }

        map<string, int> synonym_to_id;
        for (int i = 0; i < synonyms.size(); ++i) {
        	for (int j = 0; j < 2; ++j) {
        		if (synonym_to_id.find(synonyms[i][j]) == synonym_to_id.end()) {
        			synonym_to_id[synonyms[i][j]] = synonym_to_id.size();
        		}
        	}
        }
        int n_synonyms = synonym_to_id.size();
        vector<int> group(n_synonyms, 0);
        for (int i = 0; i < synonym_to_id.size(); ++i) group[i] = i;

        for (int i = 0; i < synonyms.size(); ++i) {
        	int x = find(synonym_to_id[synonyms[i][0]], group);
        	int y = find(synonym_to_id[synonyms[i][1]], group);
        	if (x != y) {
        		group[x] = y;
        	}
        }
        vector<string> ans;
        dfs(0, vec_text, synonym_to_id, group, "", ans);
        sort(ans.begin(), ans.end());

        return ans;
    }
    void dfs(int idx, vector<string>& vec_text, map<string, int>& synonym_to_id, 
    		 vector<int>& group, string cur, vector<string>& ans) {
    	if (synonym_to_id.find(vec_text[idx]) != synonym_to_id.end()) {
    		int x = find(synonym_to_id[vec_text[idx]], group);
    		for (map<string, int>::iterator it = synonym_to_id.begin(); it != synonym_to_id.end(); ++it) {
    			if (find(it->second, group) == x) {
    				if (idx == vec_text.size() - 1) ans.push_back(cur + it->first);
    				else {
    					dfs(idx + 1, vec_text, synonym_to_id, group, cur + it->first + " ", ans);
    				}
    			}
    		}
    	} else {
    		if (idx == vec_text.size() - 1) ans.push_back(cur + vec_text[idx]);
    		else {
    			dfs(idx + 1, vec_text, synonym_to_id, group, cur + vec_text[idx] + " ", ans);
    		}
    	}
    }

    int find(int x, vector<int>& group) {
    	if (x != group[x]) group[x] = find(group[x], group);
    	return group[x];
    }
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	string s1[] = {"happy", "joy"};
	string s2[] = {"sad", "sorrow"};
	string s3[] = {"joy", "cheerful"};

	vector<vector<string> > synonyms;
	synonyms.push_back(vector<string>(s1, s1 + 2));
	synonyms.push_back(vector<string>(s2, s2 + 2));
	synonyms.push_back(vector<string>(s3, s3 + 2));
	string text = "I am happy today but was sad yesterday";

	vector<string> ans = sol.generateSentences(synonyms, text);
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << endl;
	}
	/* [1-D vector] */
	// const int a = 1;
	// int arr[] = {};
	// vector<int> nums(arr, arr + a);

	/* [2-D vector] */
	// const int rows = 1;
	// const int cols = 1;
	// int arr[rows][cols] = {{1}};
	// vector<vector<int> > grid;
	// for (int r = 0; r < rows; ++r) {
	// 	grid.push_back(vector<int>(arr[r], arr[r] + cols));
	// }

	/* [String] */
	// string str = "";

}