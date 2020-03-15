#include <iostream>
#include <vector>
using namespace std;

class RLEIterator {
public:
	RLEIterator(vector<int>& A) {
		seq = A;
		cur = 0;
	}

	int next(int n) {
		while (cur < seq.size() && seq[cur] < n) {
			cout << "cur: " << cur << endl;
			cout << "seq[cur]: " << seq[cur] << endl;
			n -= seq[cur];
			seq[cur] = 0;
			cur += 2;
		}
		cout << "cur after: " << cur << endl;
		if (cur >= seq.size()) return -1;

		seq[cur] -= n;
		return seq[cur + 1];
	}
private:
	vector<int> seq;
	int cur;
};

int main() {
	int a[] = {3, 8, 0, 9, 2, 5};
	vector<int> A(a, a + 6);
	RLEIterator *obj = new RLEIterator(A);

	cout << obj->next(2) << endl;
	cout << obj->next(1) << endl;
	cout << obj->next(1) << endl;
	cout << obj->next(2) << endl;
}