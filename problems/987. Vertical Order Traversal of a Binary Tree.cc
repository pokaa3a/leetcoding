#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// class Solution {
// public:
// 	vector<vector<int> > verticalTraversal(TreeNode* root) {
// 		map<int, vector<int> > m;
// 		map<int, vector<int> > m_y;
// 		queue<TreeNode*> q_node;
// 		queue<int> q_x;

// 		q_node.push(root);
// 		q_x.push(0);
// 		m[0].push_back(root->val);
// 		int y = 0;
// 		m_y[0].push_back(y);

// 		while (!q_node.empty()) {
// 			int q_size = q_node.size();
// 			y++;
// 			cout << "level: " << y << endl;
// 			for (int i = 0; i < q_size; ++i) {
// 				TreeNode* cur = q_node.front();
// 				cout << "val: " << cur->val << endl;
// 				int x = q_x.front();
// 				q_node.pop();
// 				q_x.pop();
// 				if (cur->left) {
// 					q_node.push(cur->left);
// 					q_x.push(x - 1);
// 					m[x - 1].push_back(cur->left->val);
// 					m_y[x - 1].push_back(y);
// 				}
// 				if (cur->right) {
// 					q_node.push(cur->right);
// 					q_x.push(x + 1);
// 					m[x + 1].push_back(cur->right->val);
// 					m_y[x + 1].push_back(y);
// 				}
// 			}
// 		}
// 		vector<vector<int> > ans;
// 		for(map<int, vector<int> >::iterator it = m.begin(); it != m.end(); ++it) {
// 			// ans.push_back(it->second);
// 			int x = it->first;
// 			// vector<int> sec = it->second;
// 			int left = 0, right = 0;
// 			for (int i = m_y[x].front(); i <= m_y[x].back(); ++i) {
// 				right = int(upper_bound(m_y[x].begin() + left, m_y[x].end(), i) - m_y[x].begin());
// 				sort(it->second.begin() + left, it->second.begin() + right);
// 				left = right;
// 			}
// 			ans.push_back(it->second);
// 		}
// 		return ans;
// 	}
// };
class Solution {
public:
    vector<vector<int> > verticalTraversal(TreeNode* root) {
        map<pair<int, int>, set<int> > mp;
        queue<TreeNode*> q_node;
        queue<pair<int, int> > q_pos;
        
        q_node.push(root);
        q_pos.push(make_pair(0, 0));
        mp[make_pair(0, 0)].insert(root->val);
        
        while (!q_node.empty()) {
            int q_size = q_node.size();
            
            for (int i = 0; i < q_size; ++i) {
                TreeNode* node = q_node.front(); q_node.pop();
                pair<int, int> pos = q_pos.front(); q_pos.pop();
                
                mp[pos].insert(node->val);
                if (node->left) {
                    q_node.push(node->left);
                    q_pos.push(make_pair(pos.first - 1, pos.second + 1));
                }
                if (node->right) {
                    q_node.push(node->right);
                    q_pos.push(make_pair(pos.first + 1, pos.second + 1));
                }
            }
        }
        vector<vector<int> > ans;
        int prev_x = mp.begin()->first.first - 1;

        for (map<pair<int, int>, set<int> >::iterator it = mp.begin(); it != mp.end(); ++it) {
            int x = it->first.first;
            if (x != prev_x) {
                ans.push_back(vector<int>());
                prev_x = x;
            }
            for (set<int>::iterator s_it = it->second.begin(); s_it != it->second.end(); ++s_it) {
                ans.back().push_back(*s_it);
            }
        }
        return ans;
    }
};

int main() {
	TreeNode* n1 = new TreeNode(1);
	TreeNode* n2 = new TreeNode(2);
	TreeNode* n3 = new TreeNode(3);
	TreeNode* n4 = new TreeNode(4);
	TreeNode* n5 = new TreeNode(6);
	TreeNode* n6 = new TreeNode(5);
	TreeNode* n7 = new TreeNode(7);

	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n2->right = n5;
	n3->left = n6;
	n3->right = n7;

	Solution sol;
	vector<vector<int> > ans = sol.verticalTraversal(n1);
	for (int i = 0; i < ans.size(); ++i) {
		for (int j = 0; j < ans[i].size(); ++j) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}