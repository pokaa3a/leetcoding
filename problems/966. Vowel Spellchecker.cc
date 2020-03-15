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
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string> ans;
        set<string> all_words;
        map<string, string> lower_to_first;
        map<string, string> vowel_err;

        for (int i = 0; i < wordlist.size(); ++i) {
        	string word = wordlist[i];
        	string low = to_lower(word);
        	string rm_v = rm_vowels(word);

        	all_words.insert(word);
        	if (lower_to_first.find(low) == lower_to_first.end()) {
        		lower_to_first[low] = word;
        		// cout << "low = " << low << " word = " << word << endl;
        	}
        	if (vowel_err.find(rm_v) == vowel_err.end()) {
        		vowel_err[rm_v] = word;
        		// cout << "rm_v = " << rm_v << " word = " << word << endl;
        	}
        }

        for (int i = 0; i < queries.size(); ++i) {
        	string word = queries[i];
        	string low = to_lower(word);
        	string rm_v = rm_vowels(word);

        	if (all_words.find(word) != all_words.end()) {
        		ans.push_back(word);
        	} else if (lower_to_first.find(low) != lower_to_first.end()) {
        		ans.push_back(lower_to_first[low]);
        	} else if (vowel_err.find(rm_v) != vowel_err.end()) {
        		ans.push_back(vowel_err[rm_v]);
        	} else {
        		ans.push_back("");
        	}
        }

        return ans;
    }

   	string to_lower(string s) {
   		string out = s;
   		transform(out.begin(), out.end(), out.begin(), ::tolower);
   		return out;
   	}
   	string rm_vowels(string s) {
   		string low = to_lower(s);
   		string out = low;
   		for (int i = 0; i < out.size(); ++i) {
   			if (out[i] == 'a' || out[i] == 'e' || out[i] == 'i' || 
   				out[i] == 'o' || out[i] == 'u') {
   				out[i] = '_';
   			}
   		}
   		return out;
   	}
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	string w[] = {"YellOw"};
	string q[] = {"yollow"};
	vector<string> wordlist(w, w + 1);
	vector<string> queries(q, q + 1);
	vector<string> ans = sol.spellchecker(wordlist, queries);

	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << " ";
	}
	cout << endl;

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