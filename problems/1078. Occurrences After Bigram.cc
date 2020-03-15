#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

// class Solution {
// public:
//     vector<string> findOcurrences(string text, string first, string second) {
//         vector<string> text_vec;
//         stringstream ss(text);
//         string token;

//         while (getline(ss, token, ' ')) {
//         	text_vec.push_back(token);
//         }

//         vector<string> res;
//         for (int i = 0; i < text_vec.size() - 2; ++i) {
//         	if (text_vec[i] == first && text_vec[i + 1] == second) {
//         		res.push_back(text_vec[i + 2]);
//         	}
//         }
//         return res;
//     }
// };

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        stringstream ss(text);
        string token;
        vector<string> ans;
        vector<string> tokens;
        while (getline(ss, token, ' ')) {
            tokens.push_back(token);
        }
        for (int i = 2; i < tokens.size(); ++i) {
            if (tokens[i - 1] == second &&
                tokens[i - 2] == first) {
                ans.push_back(tokens[i]);
            }
        }
        return ans;
    }
};

int main() {
	string text = "alice is a good girl she is a good student";
	string first = "a";
	string second = "good";

	Solution sol;
	vector<string> res = sol.findOcurrences(text, first, second);
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << " ";
	}
	cout << endl;
}