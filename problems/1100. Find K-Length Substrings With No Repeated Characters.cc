#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    int numKLenSubstrNoRepeats(string S, int K) {
        if (S.length() < K) return 0;
        if (K > 26) return 0;

        vector<int> window(26, 0);
        for (int i = 0; i < K - 1; ++i) {
        	window[S[i] - 'a']++;
        }
        int res = 0;
        for (int i = 0; i <= S.length() - K; ++i) {
        	window[S[i + K - 1] - 'a']++;
        	if (isValid(window)) res++;
        	window[S[i] - 'a']--;
        }
        return res;
    }
private:
	bool isValid(vector<int>& window) {
		for (int i = 0; i < window.size(); ++i) {
			if (window[i] > 1) return false;
		}
		return true;
	}
};

int main() {
	string S = "havefunonleetcode";
	int K = 5;
	Solution sol;
	cout << sol.numKLenSubstrNoRepeats(S, K) << endl;
}