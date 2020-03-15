class Trie {
private:
    struct TrieNode{€
        vector<TrieNode*> next;
        bool isEnd;
        TrieNode(): next(26), isEnd(false){};
    };
    TrieNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* ptr = root;
        for(int i=0; i<word.length(); i++){
            if(ptr->next[word[i]-'a']==NULL){
                ptr->next[word[i]-'a'] = new TrieNode();
            }
            ptr = ptr->next[word[i]-'a'];
        }
        ptr->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* ptr = root;
        for(int i=0; i<word.length(); i++){
            if(ptr->next[word[i]-'a']==NULL) return false;
            ptr = ptr->next[word[i]-'a'];
        }
        return ptr->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* ptr = root;
        for(int i=0; i<prefix.length(); i++){
            if(ptr->next[prefix[i]-'a']==NULL) return false;
            ptr = ptr->next[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */