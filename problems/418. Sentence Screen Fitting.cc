#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int wordsTyping1(vector<string>& sentence, int rows, int cols){
		int times = 0, word = 0;
		int last_space = cols+1;
		int sum = 0;

		for(int i=0; i<sentence.size(); i++){
			sum += sentence[i].size()+1;
		}

		for(int i=0; i<rows; i++){
			last_space = cols+1;
			times += last_space/sum;
			last_space %= sum;
			while(last_space >= (sentence[word].size()+1)){
				last_space -= sentence[word++].size()+1;
				if(word==sentence.size()){
					times++;
					word = 0;
				}
			}
		}
		return times;
	}
	
	int wordsTyping2(vector<string>& sentence, int rows, int cols){
        int sum = 0;
        for (int s=0; s<sentence.size(); s++) {
            if (sentence[s].size() > cols) {
                return 0;
            }
            sum += sentence[s].size()+1;
        }
        int length = sentence.size();
        int index = 0, count = 0;
        for (int i = 0; i < rows; i++) {
            int locations = cols + 1;
            count += locations / sum;
            locations %= sum;
            while (locations >= sentence[index].size() + 1) {
                locations -= sentence[index++].size() + 1;
                if (index == length) {
                    count++;
                    index = 0;
                }
            }
        }
        return count;
	}
};

int main(){
	int rows = 8, cols = 7;
	string sentenceArray[] = {"f", "p", "a"};
	vector<string> sentence(sentenceArray, sentenceArray+3);

	Solution sol;

	cout<<sol.wordsTyping1(sentence, rows, cols);

}