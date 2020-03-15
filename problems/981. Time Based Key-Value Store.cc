#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

/*
class TimeMap {
private:
	unordered_map<string, unordered_map<int, string> > kt_map;
	unordered_map<string, vector<int> > k_t_vec;
public:
	TimeMap () {
		
	}

	void set(string key, string value, int timestamp) {
		kt_map[key][timestamp] = value;
		k_t_vec[key].push_back(timestamp);
	}

	string get(string key, int timestamp) {
		if (k_t_vec.find(key) == k_t_vec.end()) return "";

		vector<int>::iterator it = upper_bound(k_t_vec[key].begin(), k_t_vec[key].end(), timestamp);
		if (it == k_t_vec[key].begin()) return "";

		return kt_map[key][*(--it)];
	}
};
*/
class TimeMap {
public:
	TimeMap() {

	}
	void set(string key, string value, int timestamp) {
		time_map[key].push_back(timestamp);
		str_map[key].push_back(value);
	}
	string get(string key, int timestamp) {
		if (time_map.find(key) == time_map.end()) return "";
		int found = upper_bound(time_map[key].begin(), time_map[key].end(), timestamp) - time_map[key].begin();
		if (found == 0) return "";
		return str_map[key][found - 1];

	}
private:
	unordered_map<string, vector<int> > time_map;
	unordered_map<string, vector<string> > str_map;
};

int main() {

	TimeMap *obj = new TimeMap();
	obj->set("foo", "bar", 1);
	cout << obj->get("foo", 1) << endl;
	cout << obj->get("foo", 3) << endl;
	obj->set("foo", "bar2", 4);
	cout << obj->get("foo", 4) << endl;
	cout << obj->get("foo", 5) << endl;

}