#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int maxProduct(vector<string> &words) {
		if (!words.size()) return 0;
		vector<int> values = vector<int>(words.size(), 0);

		for (int i = 0; i < words.size(); ++i) {
			string tmp = words[i];
			for (int j = 0; j < tmp.length(); ++j) {
				values[i] |= 1 << int(tmp[j] - 'a');
			}
		}

		int max_product = 0;
		for (int i = 0; i < words.size(); ++i) {
			int x = values[i];
			for (int j = i + 1; j < words.size(); ++j) {
				int y = values[j];
				if (x & y) continue;
				max_product = max(max_product, int(words[i].length() * words[j].length()));
			}
		}
		return max_product;
	}
};

int main() {
	vector<string> words;
	words.push_back("a");
	words.push_back("aa");
	words.push_back("aaa");
	// words.push_back("d");
	// words.push_back("cd");
	// words.push_back("bcd");
	// words.push_back("abcd");
	Solution sol;
	cout << sol.maxProduct(words) << endl;
}