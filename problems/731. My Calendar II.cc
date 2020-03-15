#include <iostream>
#include <map>
using namespace std;

class MyCalendarTwo {
private:
	map<int, int> calendar;
public:
	MyCalendarTwo() {

	}

	bool book (int start, int end) {

		map<int, int>::iterator upper_it = calendar.upper_bound(start);
		int num_start_events = 0;
		if (upper_it != calendar.begin()) {
			--upper_it;
			num_start_events = upper_it->second;
		}
		for (map<int, int>::iterator it = upper_it; it != calendar.lower_bound(end); ++it) {
			if (it->second >= 2) {
				return false;
			}
		}
		calendar[start] = num_start_events;
		calendar[end] = (--calendar.upper_bound(end))->second;
		for (map<int, int>::iterator it = calendar.lower_bound(start); it != calendar.lower_bound(end); it++) {
			it->second++;
		}
		return true;
	}

};


int main() {
	MyCalendarTwo cal = MyCalendarTwo();
	cout << cal.book(47, 50) << endl;
	cout << cal.book(1, 10) << endl;
	cout << cal.book(20, 27) << endl;
	cout << cal.book(15, 23) << endl;
}