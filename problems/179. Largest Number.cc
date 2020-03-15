#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool myfunction (int i,int j) { 
    return (to_string(i) + to_string(j) > to_string(j) + to_string(i)); 
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), myfunction);
        string s = "";
        for (auto n : nums) {
            s = s + to_string(n);
        }
        return (s[0] == '0' ? "0" : s);
    }
};
