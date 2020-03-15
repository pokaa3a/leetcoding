#include <iostream>
#include <vector>
using namespace std;

// class Solution {
// public:
// 	vector<vector<int> > intervalIntersection(vector<vector<int> >& A,
// 											  vector<vector<int> >& B) {
// 		int i = 0, j = 0;
// 		vector<vector<int> > res;
// 		while (i < A.size() && j < B.size()) {
// 			// cout << "a: [" << A[i][0] << ", " << A[i][1] << "]" << endl;
// 			// cout << "b: [" << B[i][0] << ", " << B[j][1] << "]" << endl;
// 			findIntersection(A[i], B[j], res);

// 			if (A[i][1] < B[j][1]) {
// 				i++;
// 			} else if (B[j][1] < A[i][1]) {
// 				j++;
// 			} else {
// 				i++;
// 				j++;
// 			}
// 		}

// 		return res;
// 	}
// private:
// 	void findIntersection(vector<int> &A, vector<int> &B, vector<vector<int> > &res) {
// 		vector<int> new_interval;
// 		if (A[0] <= B[0] && B[0] <= A[1]) {
// 			new_interval.push_back(B[0]);
// 			new_interval.push_back(min(A[1], B[1]));
// 		} else if (B[0] <= A[0] && A[0] <= B[1]) {
// 			new_interval.push_back(A[0]);
// 			new_interval.push_back(min(A[1], B[1]));
// 		} else {
// 			return;
// 		}
// 		// cout << "new interval: [" << new_interval[0] << ", " << new_interval[1] << "]" << endl; 
// 		if (res.size() > 0 && res.back()[1] == new_interval[0]) {
// 			res.back()[1] = new_interval[1];
// 		} else {
// 			res.push_back(new_interval);
// 		}
// 	}
// };

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int i = 0, j = 0;
        vector<vector<int> > ans;
        while (i < A.size() && j < B.size()) {
            int A_lft = A[i][0], A_rht = A[i][1];
            int B_lft = B[j][0], B_rht = B[j][1];
            
            if (A_rht >= B_lft && A_rht <= B_rht) {
                int lft = max(A_lft, B_lft);
                int interval[] = {lft, A_rht};
                ans.push_back(vector<int>(interval, interval + 2));
                i++;
            } else if (B_rht >= A_lft && B_rht <= A_rht) {
                int lft = max(A_lft, B_lft);
                int interval[] = {lft, B_rht};
                ans.push_back(vector<int>(interval, interval + 2));
                j++;
            } else {
                if (A_lft < B_lft) i++;
                else j++;
            }
        }
        return ans;
    }
};

int main() {
	int a0[] = {0, 2};
	int a1[] = {5, 12};
	int a2[] = {12, 23};
	int a3[] = {24, 25};

	int b0[] = {1, 5};
	int b1[] = {8, 12};
	int b2[] = {12, 24};
	int b3[] = {25, 26};

	vector<vector<int> > A;
	vector<vector<int> > B;

	A.push_back(vector<int>(a0, a0 + 2));
	A.push_back(vector<int>(a1, a1 + 2));
	A.push_back(vector<int>(a2, a2 + 2));
	A.push_back(vector<int>(a3, a3 + 2));

	B.push_back(vector<int>(b0, b0 + 2));
	B.push_back(vector<int>(b1, b1 + 2));
	B.push_back(vector<int>(b2, b2 + 2));
	B.push_back(vector<int>(b3, b3 + 2));

	Solution sol;
	vector<vector<int> > res = sol.intervalIntersection(A, B);
	for (int i = 0; i < res.size(); ++i) {
		cout << "[" << res[i][0] << ", " << res[i][1] << "]" << endl;
	}

}