#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <sstream>
#include <cmath>
#include <numeric>
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

void traverse(TreeNode* root) {
    if (!root) return;
    cout << root->val << endl;
    traverse(root->left);
    traverse(root->right);
}

/* Solution */
const int MOD = 1000000007;
class LRUCache {
private:
    int maxCap;
    list<int> used; // key
    map<int, pair<int, list<int>::iterator>> cache; // key,<val,iterator>
public:
    LRUCache(int capacity) {
        maxCap = capacity;
    }
    
    int get(int key) {
        auto it = cache.find(key);
        if(it==cache.end()) return -1;  // not exist
        touch(it);
        return it->second.first;
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);
        if(it!=cache.end()) touch(it);  // already exist, touch it only
        else {
            if(cache.size()==maxCap){   // if full
                cache.erase(used.back());
                used.pop_back();
            }
            used.push_front(key);
        }
        cache[key] = {value, used.begin()};
    }
    
    void touch(map<int, pair<int, list<int>::iterator>>::iterator it){
        int key = it->first;
        used.erase(it->second.second);
        used.push_front(key);
        it->second.second = used.begin();
    }
};

int main() {
    /* Solution */
    Solution sol;

    /* Test cases */


}