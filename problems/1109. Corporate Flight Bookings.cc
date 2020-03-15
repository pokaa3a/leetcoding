#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int> >& bookings, int n) {
        vector<int> books(n + 2, 0);
        for (int i = 0; i < bookings.size(); ++i) {
        	int f1 = bookings[i][0];
        	int f2 = bookings[i][1];
        	int seats = bookings[i][2];
        	books[f1] += seats;
        	books[f2 + 1] -= seats;
        }
        vector<int> res;
        for (int i = 0; i < n; ++i) {
        	int pre = i == 0 ? 0 : res.back();
        	res.push_back(pre + books[i + 1]);
        }
        return res;
    }
};

int main() {
	const int n_books = 3;
	int bookings_arr[n_books][3] = {{1,2,10}, {2,3,20}, {2,5,25}};

	vector<vector<int> > bookings;
	for (int i = 0; i < n_books; ++i) {
		bookings.push_back(vector<int>(bookings_arr[i], bookings_arr[i] + 3));
	}
	int n = 5;
	Solution sol;
	vector<int> res = sol.corpFlightBookings(bookings, n);
	for (int i = 0; i < res.size(); ++i) cout << res[i] << " ";
	cout << endl;
}