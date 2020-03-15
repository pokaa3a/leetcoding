/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return node;
        map<int, UndirectedGraphNode*>::iterator it = hash.find(node->label);
        if(it==hash.end()){     // not found
            UndirectedGraphNode* newNode = new UndirectedGraphNode(node->label);
            hash[node->label] = newNode;
            for(int x=0; x<node->neighbors.size(); x++){
                newNode->neighbors.push_back(cloneGraph(node->neighbors[x]));
            }
            return newNode;
        } else {                // found
            return it->second;
        }
    }
private:
    map<int, UndirectedGraphNode*> hash;
};