#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
	string addBoldTag(string s, vector<string>& dict) {
		map<int, int> pos;	// start-idx, end-idx
		for (int i = 0; i < dict.size(); ++i) {
			string word = dict[i];
			int start_idx = s.find(word);
			while (start_idx != string::npos) {
				// cout << pos[start_idx] << endl;
				pos[start_idx] = max(pos[start_idx], start_idx + (int)word.length() - 1);
				start_idx = s.find(word, start_idx + 1);
			}
		}
		string ans = "";
		int start = 0, end = -1;
		for (map<int, int>::iterator it = pos.begin(); it != pos.end(); ++it) {
			if (it->first <= end + 1) {
				end = max(end, it->second);
			} else {
				if (end - start + 1 > 0) {
					ans += "<b>" + s.substr(start, end - start + 1) + "</b>";
				}
				ans += s.substr(end + 1, (it->first - 1) - (end + 1) + 1);
				start = it->first;
				end = it->second;
			}
		}
		if (end - start + 1 > 0) {
			ans += "<b>" + s.substr(start, end - start + 1) + "</b>";
		}
		ans += s.substr(end + 1);
		return ans;
	}
};

int main() {
	string s = "aaabbcc";
	vector<string> dict;
	dict.push_back("aaa");
	dict.push_back("aab");
	dict.push_back("bc");
	// dict.push_back("rb");
	// dict.push_back("km");
	// dict.push_back("yz");
	// dict.push_back("zz");
	// dict.push_back("vo");
	// dict.push_back("qx");
	// dict.push_back("ef");
	// dict.push_back("vx");
	// dict.push_back("kc");
	// dict.push_back("wt");
	// dict.push_back("pk");
	Solution sol;
	cout << sol.addBoldTag(s, dict) << endl;
}