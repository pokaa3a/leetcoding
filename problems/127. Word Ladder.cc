class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> dict;
        for(int i=0; i<wordList.size(); i++){
            dict.insert(wordList[i]);
        }
        queue<string> toVisit;
        nextWord(beginWord, toVisit, dict);
        int dist = 2;
        while(!toVisit.empty()){
            int size = toVisit.size();
            for(int i=0; i<size; i++){
                string word = toVisit.front();
                toVisit.pop();
                if(word==endWord) return dist;
                nextWord(word, toVisit, dict);
            }
            dist++;
        }
        return 0;
    }
    void nextWord(string word, queue<string> &toVisit, set<string> &dict){
        //dict.erase(word);
        for(int i=0; i<word.length(); i++){     // word[i]
            char letter = word[i];
            for(int j=0; j<26; j++){
                word[i] = 'a'+j;
                if(dict.find(word)!=dict.end()){
                    toVisit.push(word);
                    dict.erase(word);
                }
            }
            word[i] = letter;
        }
    }
};