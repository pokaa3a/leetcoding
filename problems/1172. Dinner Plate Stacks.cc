#include <iostream>
#include <stack>
#include <vector>
#include <set>
using namespace std;

// class DinnerPlates {
// public:
// 	DinnerPlates(int capacity) {
// 		cap = capacity;
// 	}

// 	void push(int val) {
// 		if (avabl.empty()) {
// 			plates.push_back(stack<int>());
// 			plates.back().push(val);
// 			if (cap > 1) {
// 				avabl.insert(plates.size() - 1);
// 			}
// 		} else {
// 			plates[*avabl.begin()].push(val);
// 			if (plates[*avabl.begin()].size() == cap) {
// 				avabl.erase(avabl.begin());
// 			}
// 		}
// 	}

// 	int pop() {
// 		int out;
// 		if (plates.size() == 0) {
// 			out = -1;
// 		} else {
// 			out = plates.back().top();
// 			plates.back().pop();
// 			if (plates.back().size() == 0) {
// 				plates.pop_back();
// 				if (avabl.find(plates.size()) != avabl.end()) {
// 					avabl.erase(plates.size());
// 				}
// 			} else {
// 				avabl.insert(plates.size() - 1);
// 			}
// 		}
// 		return out;
// 	}

// 	int popAtStack(int index) {
// 		int out;
// 		if (index >= plates.size() || 
// 			plates[index].size() == 0) {
// 			out = -1;
// 		} else {
// 			out = plates[index].top();
// 			plates[index].pop();
// 			if (plates[index].size() == 0) {
// 				if (index == plates.size() - 1) {
// 					plates.pop_back();
// 					if (avabl.find(plates.size()) != avabl.end()) {
// 						avabl.erase(plates.size());
// 					}
// 				} else {
// 					avabl.insert(index);
// 				}
// 			} else {
// 				avabl.insert(index);
// 			}
// 		}
// 		return out;
// 	}
// private:
// 	int cap;
// 	vector<stack<int> > plates;
// 	set<int> avabl;
// };

class DinnerPlates {
private:
    int cap;
    vector<stack<int> > plates;
    set<int> un_full;
    
public:
    DinnerPlates(int capacity) {
        cap = capacity;
    }
    
    void push(int val) {
        if (un_full.size() == 0) {
            if (cap > 1) un_full.insert(plates.size());
            plates.push_back(stack<int>());
            plates.back().push(val);
        } else {
            int idx = *un_full.begin();
            plates[idx].push(val);
            if (plates[idx].size() == cap) {
                un_full.erase(idx);
            }
        }
    }
    
    int pop() {
        if (plates.size() == 0) return -1;
        int ans = plates.back().top();
        plates.back().pop();
        un_full.insert(plates.size() - 1);
        while (!plates.empty() && plates.back().empty()) {
        	plates.pop_back();
        	if (un_full.count(plates.size()) > 0) {
        		un_full.erase(plates.size());
        	}
        }
        return ans;
    }
    
    int popAtStack(int index) {
        if (index >= plates.size() || plates[index].empty()) return -1;
        int ans = plates[index].top();
        plates[index].pop();
        un_full.insert(index);
        while (!plates.empty() && plates.back().empty()) {
        	plates.pop_back();
        	if (un_full.count(plates.size()) > 0) {
        		un_full.erase(plates.size());
        	}
        }
        return ans;
    }
};

int main() {
	DinnerPlates D = DinnerPlates(2);
	D.push(1);
	D.push(2);
	D.push(3);
	cout << D.popAtStack(0) << endl;
	cout << D.popAtStack(0) << endl;
	D.push(1);
	cout << D.popAtStack(0) << endl;
	// D.push(4);
	// D.push(5);


	// cout << D.popAtStack(0) << endl;
	// D.push(20);
	// D.push(21);
	// cout << D.popAtStack(0) << endl;
	// cout << D.popAtStack(2) << endl;
	// cout << D.pop() << endl;
	// cout << D.pop() << endl;
	// cout << D.pop() << endl;
	// cout << D.pop() << endl;
	// cout << D.pop() << endl;
}