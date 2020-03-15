#include <iostream>
#include <vector>
#include <map>
using namespace std;

// class Solution {
// public:
// 	int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
//     	int n = values.size();
//     	vector<pair<int, int> > items;
//     	for (int i = 0; i < n; ++i) {
//     		items.push_back(make_pair(values[i], labels[i]));
//     	}

//     	map<int, int> count;
//     	sort(items.begin(), items.end(), greater<pair<int, int> >());
//     	int added = 0, res = 0;
//     	for (int i = 0; i < items.size() && added < num_wanted; ++i) {
//     		int val = items[i].first;
//     		int lab = items[i].second;
//     		if (count[lab] < use_limit) {
//     			res += val;
//     			count[lab]++;
//     			added++;
//     		}
//     	}
//     	return res;
//     }
// };

class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        map<int, vector<int> > hash;
        for (int i = 0; i < values.size(); ++i) {
            hash[values[i]].push_back(i);
        }
        
        map<int, int> count;
        int used = 0, ans = 0;
        for (map<int, vector<int>>::reverse_iterator it = hash.rbegin(); it != hash.rend() && used < num_wanted; ++it) {
            int val = it->first;
            vector<int>& labs = it->second;
            for (int i = 0; i < labs.size(); ++i) {
                int lab = labels[labs[i]];
                if (count.find(lab) != count.end() && count[lab] == use_limit) continue;
                else {
                    ans += val;
                    count[lab]++;
                    used++;
                }
                if (used == num_wanted) break;
            }
        }
        return ans;
    }
};

int main() {
	int v[] = {5,4,3,2,1};
	int l[] = {1,3,3,3,2};
	int num_wanted = 3, use_limit = 2;
	vector<int> values(v, v + 5);
	vector<int> labels(l, l + 5);

	Solution sol;
	cout << sol.largestValsFromLabels(values, labels, num_wanted, use_limit) << endl;
}