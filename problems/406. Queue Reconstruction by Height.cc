#include <iostream>
#include <vector>

using namespace std;

bool comp(pair<int, int>p1, pair<int, int>p2){
	return p1.first > p2.first || (p1.first==p2.first && p1.second<p2.second);
}

class Solution {
public:
	vector<pair<int, int> > reconstructQueue(vector<pair<int, int> >& people){

		sort(people.begin(), people.end(), comp);
		vector<pair<int, int> > res;
		for(int i=0; i<people.size(); i++){
			res.insert(res.begin()+people[i].second, people[i]);
		}
		return res;
	}
};


int main(){
	vector<pair<int, int> > people;
	people.push_back(pair<int, int>(5,0));
	people.push_back(pair<int, int>(7,0));
	people.push_back(pair<int, int>(5,2));
	people.push_back(pair<int, int>(6,1));
	people.push_back(pair<int, int>(4,4));
	people.push_back(pair<int, int>(7,1));

	Solution sol;
	vector<pair<int, int> > res = sol.reconstructQueue(people);

	for(int i=0; i<res.size(); i++){
		cout<<res[i].first<<", "<<res[i].second<<endl;
	}
}