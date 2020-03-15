#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	bool canTransform(string start, string end) {
		int i = 0, j = 0;
		while (i < start.length() && j < end.length()) {
			while (i < start.length() - 1 && start[i] == 'X') i++;
			while (j < end.length() - 1 && end[j] == 'X') j++;

			// cout << "i: " << i << ", j: " << j << endl;
			// cout << "start[i]: " << start[i] << ", " << "end[j]: " << end[j] << endl;

			if (start[i] != end[j]) return false;
			if (start[i] == 'R' && j < i) return false;
			if (start[i] == 'L' && i < j) return false;
			i++;
			j++;
		}
		return true;
	}
};

// class Solution {
// public:
// 	bool canTransform(string start, string end) {
// 		int next_R_start = start.find("R");
// 		int next_L_start = start.find("L");
// 		int next_R_end = end.find("R");
// 		int next_L_end = end.find("L");
// 		while (next_R_start != string::npos && next_L_start != string::npos) {
// 			if (next_R_end == string::npos || next_L_end == string::npos) return false;
// 			if (next_R_end < next_R_start) return false;
// 			if (next_L_end > next_L_start) return false;

// 			if (next_R_start < next_L_start) {
// 				if (next_R_end > next_L_end) return false;
// 				next_R_start = start.find("R", next_R_start + 1);
// 				next_R_end = end.find("R", next_R_end + 1);
// 			} else {
// 				if (next_R_end < next_L_end) return false;
// 				next_L_start = start.find("L", next_L_start + 1);
// 				next_L_end = end.find("L", next_L_end + 1);
// 			}
// 		}

// 		if (next_R_start == string::npos) {
// 			if (next_R_end != string::npos) return false;
// 			while (next_L_start != string::npos) {
// 				if (next_L_end == string::npos) return false;
// 				if (next_L_end > next_L_start) return false;
// 				next_L_start = start.find("L", next_L_start + 1);
// 				next_L_end = end.find("L", next_L_end + 1);
// 			}
// 		}
// 		if (next_L_start == string::npos) {
// 			if (next_L_end != string::npos) return false;
// 			while (next_R_start != string::npos) {
// 				if (next_R_end == string::npos) return false;
// 				if (next_R_end < next_R_start) return false;
// 				next_R_start = start.find("R", next_R_start + 1);
// 				next_R_end = end.find("R", next_R_end + 1);
// 			}
// 		}
// 		return true;
// 	}
// };



int main() {
	string start = "XXRXXLXLXLXXRXXLXLLX";
	string end   = "XXXRLLLXXXXXXXRLLLXX";
	// string start = "X";
	// string end   = "R";
	Solution sol;
	cout << sol.canTransform(start, end) << endl;

}