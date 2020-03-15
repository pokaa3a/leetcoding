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

const int MOD = 1000000007;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* Solution */
struct suffix {
	int index;
	int rank[2];
};

int cmp (struct suffix a, struct suffix b) {
	return (a.rank[0] == b.rank[0]) ? (a.rank[1] < b.rank[1] ? 1 : 0) : (a.rank[0] < b.rank[0] ? 1 : 0);
}

vector<int> buildSuffixArray(string txt) {
	int n = txt.size();
	struct suffix suffixes[n]; 
	for (int i = 0; i < n; i++) { 
		suffixes[i].index = i; 
		suffixes[i].rank[0] = txt[i] - 'a'; 
		suffixes[i].rank[1] = ((i+1) < n)? (txt[i + 1] - 'a'): -1; 
	} 

	sort(suffixes, suffixes+n, cmp); 
	int ind[n];
	
	for (int k = 4; k < 2*n; k = k*2) { 
		int rank = 0; 
		int prev_rank = suffixes[0].rank[0]; 
		suffixes[0].rank[0] = rank; 
		ind[suffixes[0].index] = 0; 
	
		// Assigning rank to suffixes 
		for (int i = 1; i < n; i++) { 
			if (suffixes[i].rank[0] == prev_rank && 
					suffixes[i].rank[1] == suffixes[i-1].rank[1]) 
			{ 
				prev_rank = suffixes[i].rank[0]; 
				suffixes[i].rank[0] = rank; 
			} 
			else{ 
				prev_rank = suffixes[i].rank[0]; 
				suffixes[i].rank[0] = ++rank; 
			} 
			ind[suffixes[i].index] = i; 
		} 

		for (int i = 0; i < n; i++) { 
			int nextindex = suffixes[i].index + k/2; 
			suffixes[i].rank[1] = (nextindex < n)? 
								suffixes[ind[nextindex]].rank[0]: -1; 
		} 
		sort(suffixes, suffixes+n, cmp); 
	} 

	vector<int>suffixArr; 
	for (int i = 0; i < n; i++) 
		suffixArr.push_back(suffixes[i].index); 

	return  suffixArr; 
}
vector<int> kasai(string txt, vector<int> suffixArr) { 
	int n = suffixArr.size(); 

	// To store LCP array 
	vector<int> lcp(n, 0); 
	vector<int> invSuff(n, 0); 

	for (int i=0; i < n; i++) 
		invSuff[suffixArr[i]] = i; 
		
	int k = 0;  
	for (int i=0; i<n; i++) { 
		if (invSuff[i] == n-1) { 
			k = 0; 
			continue; 
		} 
		int j = suffixArr[invSuff[i]+1];
		while (i+k<n && j+k<n && txt[i+k]==txt[j+k]) 
			k++; 
	
		lcp[invSuff[i]] = k;
		if (k>0) 
			k--; 
	} 
	return lcp; 
}
class Solution {
public:
    string lastSubstring(string s) {
        vector<int> suffixArr = buildSuffixArray(s);
        return s.substr(suffixArr.back());
    }
};
// class Solution {
// public:
//     string lastSubstring(string s) {
//         int n = s.size();
//         char maxi = 'a';
//         vector<int> prev_ids;
//         unordered_set<int> prev_set;
//         for (int i = 0; i < s.size(); ++i) {
//             if (s[i] > maxi) {
//                 prev_ids = vector<int>(1, i);
//                 prev_set.clear();
//                 prev_set.insert(i);
//                 maxi = s[i];
//             } else if (s[i] == maxi) {
//                 prev_ids.push_back(i);
//             }
//         }
//         if (prev_ids.size() == s.size()) return s;
//         string str = "";
//         str += maxi;

//         while (prev_ids.size() > 1) {
//         	maxi = 'a';
//         	vector<int> cur_ids;
//         	for (int i = 0; i < prev_ids.size(); ++i) {
//         		int idx = prev_ids[i];
//         		if (idx + 1 >= n) continue;
//         		if (s[idx + 1] > maxi) {
//         			cur_ids = vector<int>(1, idx + 1);
//         			maxi = s[idx + 1];
//         		} else if (s[idx + 1] == maxi) {
//         			cur_ids.push_back(idx + 1);
//         		}
//         	}
//         	str += maxi;
//         	prev_ids = cur_ids;
//         }
//         int found = s.find(str);
//         return s.substr(found);
//     }
// };

int main() {
	// Solution
	Solution sol;

	// Test cases
	string s = "leetcode";
	cout << sol.lastSubstring(s) << endl;

}