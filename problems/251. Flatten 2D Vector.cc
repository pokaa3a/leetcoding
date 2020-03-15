#include <iostream>
#include <vector>
using namespace std;

class Vector2D {
private:
	int rows;
	int cols;
	int curr_row;
	int curr_col;
	vector<vector<int> > vv;
public:
	Vector2D(vector<vector<int> > &v) {
		rows = v.size();
		curr_row = 0;
		curr_col = 0;
		if (rows == 0) {
			cols = 0;
		} else {
			cols = v[0].size();
		}
		vv = v;
	}

	int next() {
		this->hasNext();
		return vv[curr_row][curr_col++];
	}

	bool hasNext() {
		while (curr_col >= cols) {
			if (++curr_row >= rows) {
				return false;
			}
			curr_col = 0;
			cols = vv[curr_row].size();
		}
		return true;
	}
};

int main() {
	int array0[] = {};
	int array1[] = {3};
	int array2[] = {4};
	vector<vector<int> > v;
	v.push_back(vector<int>(array0, array0));
	v.push_back(vector<int>(array1, array1 + 1));
	// v.push_back(vector<int>(array2, array2 + 1));

	Vector2D *obj = new Vector2D(v);
	// cout << obj->next() << endl;
	// cout << obj->next() << endl;
	// cout << obj->next() << endl;
	cout << obj->hasNext() << endl;
	// cout << obj->hasNext() << endl;
	cout << obj->next() << endl;
	cout << obj->hasNext() << endl;
}