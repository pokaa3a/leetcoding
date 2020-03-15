#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string> >& people) {
        map<string, int> skill_to_id;
        for (int i = 0; i < req_skills.size(); ++i) {
        	skill_to_id[req_skills[i]] = skill_to_id.size();
        }
        int n_skills = skill_to_id.size();
        // cout << "n_skills = " << n_skills << endl;

        vector<int> ppl_skill(people.size(), 0);
        for (int i = 0; i < people.size(); ++i) {
        	int sk = 0;
        	for (int j = 0; j < people[i].size(); ++j) {
        		sk |= (1 << skill_to_id[people[i][j]]);
        	}
        	ppl_skill[i] = sk;
        }
        vector<int> team_ppl((1 << n_skills), INT_MAX);
        team_ppl[0] = 0;
        vector<vector<int> > dp((1 << n_skills), vector<int>());
        for (int i = 0; i < ppl_skill.size(); ++i) {
        	int sk = ppl_skill[i];
        	// cout << "ppl_skill[i] = " << sk << endl;
        	for (int team_sk = 0; team_sk < (1 << n_skills); ++team_sk) {
        		int new_team_sk = team_sk | sk;
        		if (team_ppl[new_team_sk] > team_ppl[team_sk]) {
        			team_ppl[new_team_sk] = team_ppl[team_sk] + 1;
        			dp[new_team_sk] = dp[team_sk];
        			dp[new_team_sk].push_back(i);
        		}
        	}
        }
        return dp[(1 << n_skills) - 1];
    }
};

int main() {
	string rs[] = {"java", "nodejs", "reactjs"};
	vector<string> req_skills(rs, rs + 3);

	string p1[] = {"java"};
	string p2[] = {"nodejs"};
	string p3[] = {"nodejs", "reactjs"};
	vector<vector<string> > people;
	people.push_back(vector<string>(p1, p1 + 1));
	people.push_back(vector<string>(p2, p2 + 1));
	people.push_back(vector<string>(p3, p3 + 2));

	Solution sol;
	vector<int> res = sol.smallestSufficientTeam(req_skills, people);
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] << " ";
	}
	cout << endl;
}