#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int leastInterval(vector<char> &tasks, int n) {
		vector<int> task_count(26, 0);
		for (int i = 0; i < tasks.size(); ++i) {
			task_count[tasks[i] - 'A']++;
		}
		int most_freq = 0;
		int num_most_freq = 0;	// num of most frequent tasks
		for (int i = 0; i < 26; ++i) {
			if (task_count[i] > most_freq) {
				most_freq = task_count[i];
				num_most_freq = 1;
			} else if (task_count[i] == most_freq) {
				num_most_freq++;
			}
		}
		int part_count = most_freq - 1;
		int empty_slots = part_count * (n - (num_most_freq - 1));
		int available_tasks = tasks.size() - num_most_freq * most_freq;
		int num_idles = max(0, empty_slots - available_tasks);
		return tasks.size() + num_idles;
	}
};

int main() {
	char array[] = {'A', 'A', 'A', 'B', 'B', 'B', 'C', 'C', 'C', 'E'};
	vector<char> tasks(array, array + 10);
	int n = 2;
	Solution sol;
	cout << sol.leastInterval(tasks, n) << endl;;
}