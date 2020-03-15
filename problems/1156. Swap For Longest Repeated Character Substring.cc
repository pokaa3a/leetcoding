#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int maxRepOpt1(string text) {
		vector<int> total(26, 0);
		vector<int> unique_char;
		vector<int> count;

		for (int i = 0; i < text.length();) {
			char c = text[i];
			int len = 1;
			while(i + len < text.length() && text[i + len] == c) {
				len++;
			}
			total[text[i] - 'a'] += len;
			unique_char.push_back(c - 'a');
			count.push_back(len);
			i += len;
		}

		if (unique_char.size() == 1) return count[0];
		if (unique_char.size() == 2) return max(count[0], count[1]);

		int longest = 1;
		for (int i = 0; i < unique_char.size() - 2; ++i) {
			int tmp = getLongest(i, unique_char, count, total);
			longest = max(longest, tmp);
		}
		return longest;
	}
private:
	int getLongest(int i, vector<int>& unique_char, vector<int>& count, vector<int>& total) {
		int ans;
		int l1 = count[i] + (total[unique_char[i]] > count[i] ? 1 : 0);
		int l2 = count[i + 1] + (total[unique_char[i + 1]] > count[i + 1] ? 1 : 0);
		int l3 = count[i + 2] + (total[unique_char[i + 2]] > count[i + 2] ? 1 : 0);
		ans = max(max(l1, l2), l3);
		if (unique_char[i] == unique_char[i + 2] && count[i + 1] == 1) {
			int l4 = count[i] + count[i + 2] + (total[unique_char[i]] > count[i] + count[i + 2] ? 1 : 0);
			ans = max(ans, l4);
		}
		return ans;
	}
};

class Solution {
public:
    int maxRepOpt1(string text) {
        vector<pair<char, int> > v;
        map<char, int> count;
        int idx = 0;
        while (idx < text.size()) {
            char cur = text[idx];
            int x = 0;
            while (text[idx + x] == cur && idx + x < text.size()) {
                x++;
            }
            count[cur] += x;
            v.push_back(make_pair(cur, x));
            idx += x;
        }
        int ans = 0;
        for (int i = 0; i < v.size(); ++i) {
            if (i + 2 < v.size()) {
                if (v[i + 1].second == 1 && v[i].first == v[i + 2].first) {
                    if (v[i].second + v[i + 2].second == count[v[i].first]) {
                        ans = max(ans, v[i].second + v[i + 2].second);
                    } else {
                        ans = max(ans, v[i].second + v[i + 2].second + 1);
                    }
                } else {
                    if (v[i].second < count[v[i].first]) {
                        ans = max(ans, v[i].second + 1);
                    } else {
                        ans = max(ans, v[i].second);
                    }
                }
            } else {
                if (v[i].second < count[v[i].first]) {
                    ans = max(ans, v[i].second + 1);
                } else {
                    ans = max(ans, v[i].second);    
                }
            }
        }
        return ans;
    }
};


int main() {
	string text = "ababa";
	Solution sol;
	cout << sol.maxRepOpt1(text) << endl;
}