#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
    	if (S == T) return 0;
        unordered_map<int, unordered_set<int>> stop2bus;
        for (int bus_id = 0; bus_id < routes.size(); bus_id++) {
        	for (auto stop : routes[bus_id]) {
        		stop2bus[stop].insert(bus_id);
        	}
        }

        queue<int> q;					// stop
        unordered_set<int> stop_taken;  // stop
        unordered_set<int> bus_taken;	// bus
        for (int bus : stop2bus[S]) {
        	for (auto stop : routes[bus]) {
        		if (stop_taken.count(stop) > 0) continue;
        		q.push(stop);
        		stop_taken.insert(stop);
        	}
        	bus_taken.insert(bus);
        }

        int total_taken = 1;
        while (!q.empty()) {
        	int q_size = q.size();
        	for (int i = 0; i < q_size; i++) {
        		int cur_stop = q.front();
        		q.pop();

        		if (cur_stop == T) return total_taken;

        		for (auto next_bus : stop2bus[cur_stop]) {
        			if (bus_taken.count(next_bus) > 0) continue;
        			for (auto next_stop : routes[next_bus]) {
        				if (stop_taken.count(next_stop) > 0) continue;
        				q.push(next_stop);
        				stop_taken.insert(next_stop);
        			}
        			bus_taken.insert(next_bus);
        		}
        	}
        	total_taken++;
        }
        return -1;
    }
};

int main() {
	vector<vector<int>> routes = {{1,2,7}, {3,6,7}};
	int S = 1, T = 6;
	Solution sol;
	cout << sol.numBusesToDestination(routes, S, T) << endl;
}