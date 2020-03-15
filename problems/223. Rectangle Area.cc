#include <iostream>
using namespace std;

class Solution {
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int overlap = 0;
		if ((max(A, E) > min(C, G)) || (max(B, F) > min(D, H))) {
			overlap = 0;
		} else {
			overlap = (min(C, G) - max(A, E)) * (min(D, H) - max(B, F));
		}
		int area1 = (C - A) * (D - B);
		int area2 = (G - E) * (H - F);
		return area1 + area2 - overlap;
	}
};

int main() {
	int A = -3, B = 0, C = 3, D = 4, E = 0, F = -1, G = 9, H = 2;
	Solution sol;
	cout << sol.computeArea(A, B, C, D, E, F, G, H);
}