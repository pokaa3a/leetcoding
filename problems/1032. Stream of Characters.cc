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

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// class Trie {
// private:
// 	struct TrieNode {
// 		vector<TrieNode*> next;
// 		bool isEnd;
// 		TrieNode() : next(26), isEnd(false) {}
// 	};
// 	TrieNode* root;
// public:
// 	void insert(string word) {
// 		TrieNode* ptr = root;
// 		for (int i = 0; i < word.size(); ++i) {
// 			if (!ptr->next[word[i] - 'a']) {
// 				ptr->next[word[i] - 'a'] = new TrieNode();
// 			}
// 			ptr = ptr->next[word[i] - 'a'];
// 		}
// 		ptr->isEnd = true;
// 	}
// };

/* Solution */
class StreamChecker {
private:
	struct TrieNode {
		vector<TrieNode*> next;
		bool isEnd;
		TrieNode() : next(26), isEnd(false) {}
	};
	TrieNode* root;
	queue<TrieNode*> nodes;
public:
    StreamChecker(vector<string>& words) {
        root = new TrieNode();
        for (int i = 0; i < words.size(); ++i) {
        	insertWorld(words[i]);
        }
    }
    bool query(char letter) {
    	nodes.push(root);
        int q_size = nodes.size();
        
        bool ans = false;
        for (int i = 0; i < q_size; ++i) {
        	TrieNode* ptr = nodes.front(); nodes.pop();
        	if (!ptr->next[letter - 'a']) {
        		continue;
        	} else {
        		ptr = ptr->next[letter - 'a'];
        		nodes.push(ptr);
        		if (ptr->isEnd) ans = true;
        	}
        }
        return ans;
    }
    void insertWorld(string word) {
    	TrieNode* ptr = root;
    	for (int i = 0; i < word.size(); ++i) {
    		if (!ptr->next[word[i] - 'a']) {
    			ptr->next[word[i] - 'a'] = new TrieNode();
    		}
    		ptr = ptr->next[word[i] - 'a'];
    	}
    	ptr->isEnd = true;
    }
};

int main() {
	// Solution
	vector<string> words;
	words.push_back("ab");
	words.push_back("ba");
	words.push_back("aaab");
	words.push_back("abab");
	words.push_back("baa");
	StreamChecker* streamChecker = new StreamChecker(words);

	// Test cases
	// cout << streamChecker->query('a') << endl;
	// cout << streamChecker->query('a') << endl;
	// cout << streamChecker->query('a') << endl;
	// cout << streamChecker->query('a') << endl;
	cout << "query 1" << endl;
	cout << streamChecker->query('a') << endl;
	cout << "query 2" << endl;
	cout << streamChecker->query('b') << endl;
	cout << "query 3" << endl;
	cout << streamChecker->query('a') << endl;

}