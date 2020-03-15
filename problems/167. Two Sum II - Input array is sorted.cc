#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		map<int, int> m;
		vector<int> answer;
		for (int i = 0; i < numbers.size(); ++i) {
			if (m.count(target - numbers[i]) > 0) {
				answer.push_back(m[target - numbers[i]] + 1);
				answer.push_back(i + 1);
			} else {
				m[numbers[i]] = i;
			}
		}
		return answer;
	}
};

int main() {
	int array[] = {2, 7, 11, 15};
	vector<int> numbers(array, array+4);
	int target = 9;

	Solution sol;
	vector<int> answer = sol.twoSum(numbers, target);
	cout << answer[0] << ", " << answer[1];
}
