#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int> >& pipes) {
		vector<int> dj(n + 1, 0);

		for (int i = 0; i < pipes.size(); ++i) {
			swap(pipes[i][0], pipes[i][2]);
		} 

		for (int i = 0; i < n; ++i) {
			dj[i + 1] = i + 1;
			int new_well[] = {wells[i], 0, i + 1,};
			pipes.push_back(vector<int>(new_well, new_well + 3));
		}
		sort(pipes.begin(), pipes.end());

		int res = 0;
		for (int i = 0; n > 0; ++i) {
			int x = find(pipes[i][1], dj);
			int y = find(pipes[i][2], dj);
			if (x != y) {
				res += pipes[i][0];
				dj[x] = y;
				n--;
			}
		}
		return res;
	}
private:
	int find(int x, vector<int>& dj) {
		if (x != dj[x]) dj[x] = find(dj[x], dj);
		return dj[x];
	}
};

int main() {
	int n = 5;
	int wells_a[] = {46012,72474,64965,751,33304};
	vector<int> wells(wells_a, wells_a + 5);

	vector<vector<int> > pipes;
	int pipe1[] = {2,1,6719};
	int pipe2[] = {3,2,75312};
	int pipe3[] = {5,3,44918};
	pipes.push_back(vector<int>(pipe1, pipe1 + 3));
	pipes.push_back(vector<int>(pipe2, pipe2 + 3));
	pipes.push_back(vector<int>(pipe3, pipe3 + 3));

	Solution sol;
	cout << sol.minCostToSupplyWater(n, wells, pipes) << endl;

}