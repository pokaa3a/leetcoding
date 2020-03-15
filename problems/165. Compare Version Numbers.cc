#include <iostream>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

class Solution{
public:
	int compareVersion(string version1, string version2){
		stringstream ssv1(version1), ssv2(version2);
		queue<int> qv1, qv2;
		string tmp;
		while (getline(ssv1, tmp, '.')) {
			qv1.push(stoi(tmp));
		};
		while (getline(ssv2, tmp, '.')) {
			qv2.push(stoi(tmp));
		}
		while (qv1.size() > qv2.size()) {
			qv2.push(0);
		}
		while (qv2.size() > qv1.size()) {
			qv1.push(0);
		}
		while (!qv1.empty() && !qv2.empty()) {
			int v1 = qv1.front();
			qv1.pop();
			int v2 = qv2.front();
			qv2.pop();
			if (v1 > v2) return 1;
			if (v1 < v2) return -1;
		}
		return 0;
	}
};

int main(){
	string version1 = "1";
	string version2 = "1.0";
	Solution sol;
	cout << sol.compareVersion(version1, version2);
}