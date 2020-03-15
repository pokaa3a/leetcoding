#include <iostream>
#include <string>
#include <vector>
using namespace std;

class WordDictionary {
public:
	struct TrieNode {
		vector<TrieNode*> table;
		bool isEnd;
		TrieNode() : table(26), isEnd(false) {}
	};

	WordDictionary() {
		root = new TrieNode();
	}

	void addWord(string word) {
		TrieNode *p = root;
		for (int i = 0; i < word.length(); ++i) {
			char c = word[i];
			if (!p->table[c - 'a']) {
				p->table[c - 'a'] = new TrieNode();
			}
			p = p->table[c - 'a'];
		}
		p->isEnd = true;
	}

	bool search(string word) {
		TrieNode *p = root;
		return DFS(p, word);
	}

	bool DFS(TrieNode *p, string word) {
		if (word.length() > 0) {
			char c = word[0];
			if (c == '.') {
				for (int i = 0; i < 26; ++i) {
					if (p->table[i] && DFS(p->table[i], word.substr(1))) return true;
				}
				return false; 
			} else {
				if (p->table[c - 'a'] && DFS(p->table[c - 'a'], word.substr(1))) return true;
				else return false;
			}
		}
		return p->isEnd;
	}
private:
	TrieNode *root;
};

int main() {
	WordDictionary wd;
	wd.addWord("bad");
	wd.addWord("dad");
	wd.addWord("mad");
	cout << wd.search("pad");
	cout << wd.search("bad");
	cout << wd.search(".ad");
	cout << wd.search("b..");
}