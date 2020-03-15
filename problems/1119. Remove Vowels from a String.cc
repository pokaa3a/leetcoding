#include <iostream>
#include <string>
using namespace std;

// class Solution {
// public:
//     string removeVowels(string S) {
//         string res = "";
//         for (int i = 0; i < S.length(); ++i) {
//         	if (S[i] == 'a' || S[i] == 'e' || S[i] == 'i' || S[i] == 'o' || S[i] == 'u') {
//         		// do nothing
//         	} else {
//         		res += S[i];
//         	}
//         }
//         return res;
//     }
// };

class Solution {
public:
    string removeVowels(string S) {
        string ans = "";
        for (int i = 0; i < S.size(); ++i) {
            if (S[i] == 'a' || S[i] == 'e' || S[i] == 'i' || S[i] == 'o' || S[i] == 'u') {
                continue;
            }
            ans += S[i];
        }
        return ans;
    }
};

int main() {
	string S = "leetcodeisacommunityforcoders";
	Solution sol;
	cout << sol.removeVowels(S) << endl;
}