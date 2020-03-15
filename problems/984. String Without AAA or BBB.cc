#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <queue>
#include <stack>
#include <sstream>
#include <cmath>
using namespace std;

const int MOD = 1000000007;

/* Solution */
class Solution {
public:
    string strWithout3a3b(int A, int B) {
        int X = A > B ? A : B;
        int Y = A > B ? B : A;
        char x = A > B ? 'a' : 'b';
        char y = A > B ? 'b' : 'a';

        string ans = "";
        while (X > Y) {
        	if (Y == 0) {
        		for (int i = 0; i < X; ++i) {
        			ans += x;
        		}
        		return ans;
        	}
        	ans = ans + x + x + y;
        	X -= 2;
        	Y--;
        }
        for (int i = 0; i < X; ++i) {
        	ans = ans + x + y;
        }
        return ans;
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases
	int A = 4, B = 2;
	cout << sol.strWithout3a3b(A, B) << endl;
}