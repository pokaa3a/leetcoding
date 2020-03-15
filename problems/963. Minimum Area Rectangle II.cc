#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <queue>
#include <stack>
#include <sstream>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/* Solution */
const int MOD = 1000000007;
class Solution {
public:
    double minAreaFreeRect(vector<vector<int> >& points) {
        map<pair<double, double>, vector<vector<pair<double, double> > > > record;

        const double max_area = 1600000000;
        double ans = max_area;
        for (int i = 0; i < points.size() - 1; ++i) {
            pair<double, double> p1 = make_pair(points[i][0], points[i][1]);
            for (int j = i + 1; j < points.size(); ++j) {
                pair<double, double> p2 = make_pair(points[j][0], points[j][1]);
                pair<double, double> mid = make_pair((p1.first + p2.first) / 2, (p1.second + p2.second) / 2);

                vector<pair<double, double> > new_pair;
                new_pair.push_back(p1);
                new_pair.push_back(p2);

                if (record.find(mid) != record.end()) {
                    for (int k = 0; k < record[mid].size(); ++k) {
                        double aa = area(p1, p2, record[mid][k]);
                        ans = min(ans, aa);
                    }
                    record[mid].push_back(new_pair);
                } else {
                    record[mid] = vector<vector<pair<double, double> > >(1, new_pair);
                }
            }
        }
        return ans == max_area ? 0 : ans;
    }
    double area(pair<double, double> p1, pair<double, double> p2, vector<pair<double, double> >& p) {
        pair<double, double> p3 = p[0];
        pair<double, double> p4 = p[1];
        if (abs(pow(dist(p1, p2), 2) - (pow(dist(p1, p3), 2) + pow(dist(p2, p3), 2))) < 1e-5) {
            // cout << "p1 = (" << p1.first << ", " << p1.second << ")" << endl;
            // cout << "p2 = (" << p2.first << ", " << p2.second << ")" << endl;
            // cout << "p3 = (" << p3.first << ", " << p3.second << ")" << endl;
            // cout << "p4 = (" << p4.first << ", " << p4.second << ")" << endl;
            return dist(p1, p3) * dist(p2, p3);
        }
        return 1600000000;
    }
    double dist(pair<double, double> p1, pair<double, double> p2) {
        return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
    }
};

int main() {
    /* Solution */
    Solution sol;

    /* Test cases */

    /* [1-D vector] */
    // const int a = 1;
    // int arr[] = {};
    // vector<int> nums(arr, arr + a);

    /* [2-D vector] */
    const int rows = 5;
    const int cols = 2;
    // int arr[rows][cols] = {{3,1}, {1,1}, {0,1}, {2,1}, {3,3}, {3,2}, {0,2}, {2,3}};
    // int arr[rows][cols] = {{0,1}, {2,1}, {1,1}, {1,0}, {2,0}};
    int arr[rows][cols] = {{0,3}, {1,2}, {3,1}, {1,3}, {2,1}};
    vector<vector<int> > grid;
    for (int r = 0; r < rows; ++r) {
     grid.push_back(vector<int>(arr[r], arr[r] + cols));
    }
    cout << sol.minAreaFreeRect(grid) << endl;

    /* [String] */
    // string str = "";

}