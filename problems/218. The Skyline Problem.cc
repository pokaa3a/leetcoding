#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
using namespace std;

class ascending {
public:
	bool operator() (vector<int> a, vector<int> b) {
		return a[0] > b[0];	// small to large
	}
};

class descending {
public:
	bool operator() (pair<int, int> a, pair<int, int> b) {
		return a.first < b.first;	// large to small
	}
};

class Solution {
public: 
    vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings) {
    	vector<pair<int, int> > skyline;
        for (int i = 0; i < buildings.size(); ++i) {
        	int new_li = buildings[i][0];
        	int new_ri = buildings[i][1];
        	int new_hi = buildings[i][2];
        	while (!Ri_q.empty()) {
        		int ri = Ri_q.top()[0];
        		int hi = Ri_q.top()[1];
        		int building_id = Ri_q.top()[2];
        		if (ri >= new_li) break;
        		if (building_id == Hi_q.top().second) {	// is the current highest
        			Hi_q.pop();
        			if (hi != getCurrentHi()) pushSkyline(ri, getCurrentHi(), false);
        		} else {
        			finished.insert(building_id);
        		}
        		Ri_q.pop();
        	}
        	if (new_hi > getCurrentHi()) {
        		pushSkyline(new_li, new_hi, true);
        	}
        	int tmp[] = {new_ri, new_hi, i};
        	Ri_q.push(vector<int>(tmp, tmp+3));
        	Hi_q.push(make_pair(new_hi, i));
        }
        while (!Ri_q.empty()) {
        	int ri = Ri_q.top()[0];
        	int hi = Ri_q.top()[1];
        	int building_id = Ri_q.top()[2];
        	if (building_id == Hi_q.top().second) {	// is the current highest
        		Hi_q.pop();
        		if (hi != getCurrentHi()) pushSkyline(ri, getCurrentHi(), false);
        	} else {
        		finished.insert(building_id);
        	}
        	Ri_q.pop();
        }
        return getSkyline();
    }

    int getCurrentHi() {
    	while (!Hi_q.empty()) {
    		int building_id = Hi_q.top().second;
    		if (finished.count(building_id) == 0) {
    			return Hi_q.top().first;
    		} else {
    			Hi_q.pop();
    		}
    	}
    	return 0;
    }

    void pushSkyline(int x, int y, bool left) {
    	if (buf.count(x)) {
    		buf[x] = left ? max(buf[x], y) : min(buf[x], y);
    	} else {
    		buf[x] = y;
    	}
    }

    vector<pair<int, int> > getSkyline() {
    	vector<pair<int, int> > skyline;
    	for (map<int, int>::iterator it = buf.begin(); it != buf.end(); ++it) {
    		skyline.push_back(make_pair(it->first, it->second));
    	}
    	return skyline;
    }

private:
    priority_queue<vector<int>, vector<vector<int> >, ascending> Ri_q;			// each element: [ri, hi, id]
    priority_queue<pair<int, int>, vector<pair<int, int> >, descending> Hi_q;	// each element: (hi, id)
    set<int> finished;
    map<int, int> buf;
};



int main() {
	int b1[] = {2, 4, 7};
	int b2[] = {2, 4, 5};
	int b3[] = {2, 4, 6};
	// int b4[] = {15, 20, 10};
	// int b5[] = {19, 24, 8};

	vector<vector<int> > buildings;
	buildings.push_back(vector<int>(b1, b1+3));
	buildings.push_back(vector<int>(b2, b2+3));
	buildings.push_back(vector<int>(b3, b3+3));
	// buildings.push_back(vector<int>(b4, b4+3));
	// buildings.push_back(vector<int>(b5, b5+3));

    Solution sol;
    vector<pair<int, int> > skyline = sol.getSkyline(buildings);

    for (int i = 0; i < skyline.size(); ++i) {
    	cout << skyline[i].first << " " << skyline[i].second << endl;
    }
}