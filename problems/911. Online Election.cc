#include <iostream>
#include <vector>
#include <map>
using namespace std;

class TopVotedCandidate {
private:
	vector<pair<int, int> > record;
public:
	TopVotedCandidate(vector<int>& persons, vector<int>& times) {
		map<int, int> votes;	// candidate, votes
		int highest_candidate = 0;
		for (int i = 0; i < persons.size(); ++i) {
			int person = persons[i];
			int time = times[i];
			if (++votes[person] >= votes[highest_candidate]) highest_candidate = person;
			record.push_back(make_pair(time, highest_candidate));
		}
	}

	// look for i, s.t. record[i].first <= t
	int q(int t) {
		int left = 0, right = record.size() - 1;

		while (left < right) {
			int mid = (left + right + 1) / 2;
			if (record[mid].first <= t) left = mid;
			else right = mid - 1;
		}
		return record[right].second;
	}
};

int main() {
	int persons_array[] = {0, 1, 1, 0, 0, 1, 0};
	vector<int> persons(persons_array, persons_array + 7);

	int times_array[] = {0, 5, 10, 15, 20, 25, 30};
	vector<int> times(times_array, times_array + 7);

	TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
	cout << obj->q(3) << endl;
	cout << obj->q(12) << endl;
	cout << obj->q(25) << endl;
	cout << obj->q(15) << endl;
	cout << obj->q(24) << endl;
	cout << obj->q(8) << endl;
}