#include <iostream>
#include <string>
#include <utility>
#include <queue>
#include <unordered_map>
#include <stack>
using namespace std;

class compare {
public:
	bool operator() (string a, string b) {
		for (int i = 0; i < a.size(); ++i) {
			if (a[i] > b[i]) return true;
		}
		return false;
	}
};


class Solution {
public:
	vector<string> findItinerary(vector<pair<string, string> > tickets) {
		unordered_map<string, priority_queue<string, vector<string>, compare> > graph;
		for (int i = 0; i < tickets.size(); ++i) {
			string fr = tickets[i].first;
			string to = tickets[i].second;
			graph[fr].push(to);
		}

		vector<string> itinerary(1, "JFK");
		stack<string> end;
		while (graph.size()) {
			if (!graph.count(itinerary.back())) {
				end.push(itinerary.back());
				itinerary.pop_back();
				continue;
			}
			string fr = itinerary.back();
			string to = graph[fr].top();
			graph[fr].pop();
			itinerary.push_back(to);
			if (!graph[fr].size()) {
				graph.erase(fr);
			}
		}
		while (end.size()) {
			itinerary.push_back(end.top());
			end.pop();
		}
		return itinerary;
	}
};

int main () {
	vector<pair<string, string> > tickets;
	tickets.push_back(make_pair("JFK", "KUL"));
	tickets.push_back(make_pair("JFK", "NRT"));
	tickets.push_back(make_pair("NRT", "JFK"));

	Solution sol;
	vector<string> itinerary = sol.findItinerary(tickets);
	for (int i = 0; i < itinerary.size(); ++i) {
		cout << itinerary[i] << " ";
	}
	cout << endl;
}