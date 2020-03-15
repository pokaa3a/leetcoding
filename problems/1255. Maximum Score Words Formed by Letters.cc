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
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> val(words.size(), 0);
        for (int i = 0; i < words.size(); ++i) {
        	string word = words[i];
        	int v = 0;
        	for (int j = 0; j < word.size(); ++j) {
        		v += score[int(word[j] - 'a')];
        	}
        	val[i] = v;
        }

        map<char, int> count;
        for (int i = 0; i < letters.size(); ++i) {
        	count[letters[i]]++;
        }

        return knapsack(count, words, val, words.size());
    }
    int knapsack(map<char, int> count, vector<string>& words, vector<int>& val, int n) {
    	if (n == 0 || count.empty()) return 0;

    	if (!can_form(count, words[n - 1])) {
    		return knapsack(count, words, val, n - 1);
    	} else {
    		map<char, int> count_used = count;
    		for (int i = 0; i < words[n - 1].size(); ++i) {
    			count_used[words[n - 1][i]]--;
    		}
    		return max(val[n - 1] + knapsack(count_used, words, val, n - 1),
    				   knapsack(count, words, val, n - 1));
    	}
    }
	bool can_form(map<char, int> count, string word) {
		for (int i = 0; i < word.size(); ++i) {
			if (count.find(word[i]) == count.end()) return false;
			if (--count[word[i]] < 0) return false;
		}
		return true;
	}
};

int main() {
	/* Solution */
	Solution sol;

	/* Test cases */
	vector<string> words;
	words.push_back("dog");
	words.push_back("cat");
	words.push_back("dad");
	words.push_back("good");

	vector<char> letters;
	char c[] = {'a','a','c','d','d','d','g','o','o'};
	letters = vector<char>(c, c + 9);

	int s[] = {1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0};
	vector<int> score(s, s + 26);

	cout << sol.maxScoreWords(words, letters, score) << endl;

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