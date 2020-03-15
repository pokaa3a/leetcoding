#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	vector<string> invalidTransactions(vector<string>& transactions) {
		unordered_map<string, vector<int> > t_map;
		unordered_map<string, vector<int> > a_map;
		unordered_map<string, vector<string> > c_map;
		unordered_set<string> added;
		vector<string> res;

		for (int i = 0; i < transactions.size(); ++i) {
			check(transactions[i], t_map, a_map, c_map, added, res);
		}

		return res;
	}
private:
	void check(string s, unordered_map<string, vector<int> >& t_map, 
						 unordered_map<string, vector<int> >& a_map, 
						 unordered_map<string, vector<string> >& c_map, 
						 unordered_set<string>& added, 
						 vector<string>& res) {
		string name, city;
		int time, amount;
		parse(s, name, time, amount, city);
		if (t_map.find(name) != t_map.end()) {
			for (int i = 0; i < t_map[name].size(); ++i) {
				if (abs(time - t_map[name][i]) <= 60 &&
					c_map[name][i] != city) {
					string invalid_s = name + "," + to_string(t_map[name][i]) + "," + to_string(a_map[name][i]) + "," + c_map[name][i];
					if (added.find(invalid_s) == added.end()) {
						res.push_back(invalid_s);
						added.insert(invalid_s);
					}
					if (added.find(s) == added.end()) {
						res.push_back(s);
						added.insert(s);
					}
				}
			}
		}
		if (amount >= 1000) {
			if (added.find(s) == added.end()) {
				res.push_back(s);
				added.insert(s);
			}
		}
		t_map[name].push_back(time);
		a_map[name].push_back(amount);
		c_map[name].push_back(city);
	}

	void parse(string s, string& name, int& time, int& amount, string& city) {
		stringstream ss(s);
		for (int i = 0; i < 4; ++i) {
			string token;
			getline(ss, token, ',');

			if (i == 0) {
				name = token;
			} else if (i == 1) {
				time = stoi(token);
			} else if (i == 2) {
				amount = stoi(token);
			} else {
				city = token;
			}
		}
	} 
};

int main() {
	vector<string> transactions;
	transactions.push_back("alice,20,800,mtv");
	transactions.push_back("bob,50,1200,mtv");

	Solution sol;
	vector<string> res = sol.invalidTransactions(transactions);
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << endl;
	}
}