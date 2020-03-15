#include <iostream>
#include <vector>
using namespace std;

// class SnapshotArray {
// private:
// 	int num_snap;
// 	vector<vector<pair<int, int> > > a;	// pair: (snap_id, val)

// public:
// 	SnapshotArray(int length) {
// 		a.resize(length, vector<pair<int, int> >(1, make_pair(0, 0)));
// 		num_snap = 0;
// 	}

// 	void set(int index, int val) {
// 		if (a[index].back().first == num_snap) {
// 			// within same snap
// 			a[index].back().second = val;
// 		} else {
// 			// at previous snap
// 			a[index].push_back(make_pair(num_snap, val));
// 		}
// 	}

// 	int snap() {
// 		return num_snap++;
// 	}

// 	int get(int index, int snap_id) {
// 		int idx = b_search(a[index], snap_id);
// 		return a[index][idx].second;
// 	}

// 	int b_search(vector<pair<int, int> >& nums, int id) {
// 		int left = 0, right = nums.size() - 1;
// 		// find nums[i] s.t. i <= id
// 		while (left < right) {
// 			int mid = (left + right + 1) / 2;
// 			if (nums[mid].first <= id) {
// 				left = mid;
// 			} else {
// 				right = mid - 1;
// 			}
// 		}
// 		return left;
// 	}
// };

class SnapshotArray {
private:
    vector<vector<pair<int, int> > > arr;
    int snap_id;
public:
    SnapshotArray(int length) {
        snap_id = 0;
        arr.resize(length, vector<pair<int, int> >(1, make_pair(0, 0)));
    }
    
    void set(int index, int val) {
        if (arr[index].back().first == snap_id) {
            arr[index].back().second = val;    
        } else {
            arr[index].push_back(make_pair(snap_id, val));
        }
    }
    
    int snap() {
        return snap_id++;
    }
    
    int get(int index, int snap_id) {
        int i = upper_bound(arr[index].begin(), arr[index].end(), make_pair(snap_id + 1, 0)) - arr[index].begin() - 1;
        return arr[index][i].second;
    }
};

int main() {
	SnapshotArray *obj = new SnapshotArray(4);
	cout << obj->snap() << endl;
	cout << obj->snap() << endl;
	cout << obj->get(3, 1) << endl;
	obj->set(2, 4);
	cout << obj->snap() << endl;
	obj->set(1, 4);
}