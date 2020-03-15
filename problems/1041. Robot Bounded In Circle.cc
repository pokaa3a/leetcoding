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
    bool isRobotBounded(string instructions) {
        int dir = 0;	// 0: up, 1: left, 2: bot, 3: right
        vector<int> moves(4, 0);
        int left_turns = 0, right_turns = 0;

        for (int i = 0; i < instructions.size(); ++i) {
        	if (instructions[i] == 'L') {
        		left_turns++;
        		dir = (dir + 1) % 4;
        	} else if (instructions[i] == 'R') {
        		right_turns++;
        		dir = (dir - 1 + 4) % 4;
        	} else {
        		moves[dir]++;
        	}
        }
        if (moves[0] == moves[2] && moves[1] == moves[3]) return true;

        int total_turns = max(left_turns, right_turns) - min(left_turns, right_turns);
        return total_turns % 4 == 0 ? false : true;
    }
};

int main() {
	// Solution
	Solution sol;

	// Test cases
	string instructions = "RLLGGLRGLGLLLGRLRLRLRRRRLRLGRLLLGGL";
	cout << sol.isRobotBounded(instructions) << endl;

}