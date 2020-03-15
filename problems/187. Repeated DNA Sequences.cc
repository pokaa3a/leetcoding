#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		vector<string> output;
		map<int, int> dnaMap;
		int dna = 0, i = 0;
		while (i < 9) {
			dna = (dna << 3) | (s[i++] & 7);
		}
		
		while (i < s.size()) {
			dna = (dna << 3) & 0x3FFFFFFF | (s[i] & 7);
			if (dnaMap.count(dna) == 0) {
				dnaMap[dna] = 1;
			} else {
				if (dnaMap[dna] == 1) {
					output.push_back(s.substr(i - 9, 10));
				}
				dnaMap[dna]++;
			}
			i++;
		}
		return output;
	}
};

int main() {
	
	string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
	Solution sol;

	vector<string> dnas = sol.findRepeatedDnaSequences(s);

	for (int i = 0; i < dnas.size(); i++) {
		cout << dnas[i] << endl;
	}


}