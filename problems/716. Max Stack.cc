#include <iostream>
#include <stack>
using namespace std;

class MaxStack {
private:
	stack<int> st;
	stack<int> st_max;
public:
	MaxStack() {

	}

	void push(int x) {
		st.push(x);
		if (st_max.empty()) {
			st_max.push(x);
		} else {
			st_max.push(max(x, st_max.top()));
		}
	}

	int pop() {
		int t = st.top();
		st.pop();
		st_max.pop();
		return t;
	}

	int top() {
		return st.top();
	}

	int peekMax() {
		return st_max.top();
	}

	int popMax() {
		int max = st_max.top();
		stack<int> buff;
		while (st.top() != max) {
			buff.push(st.top());
			this->pop();
		}
		this->pop();
		while (!buff.empty()) {
			this->push(buff.top());
			buff.pop();
		}
		return max;
	}
};


int main() {
	MaxStack *obj = new MaxStack();

	obj->push(69);
	cout << obj->top() << endl;		// 69
	cout << obj->popMax() << endl; 	// 69
	obj->push(-92);
	cout << obj->pop() << endl;		// -92
	obj->push(-83);
	cout << obj->peekMax() << endl;	// -83
	obj->push(-26);
	cout << obj->pop() << endl;		// -26
	obj->push(69);
	cout << obj->pop() << endl;		// 69		

}