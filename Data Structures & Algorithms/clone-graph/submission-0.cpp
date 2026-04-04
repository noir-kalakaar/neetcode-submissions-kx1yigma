/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        map<Node*,Node*> oldNew;
        return dfs(node, oldNew);
    }
    Node* dfs (Node* node, map<Node*,Node*>& oldNew){
        if(node==nullptr)return nullptr;
        if(oldNew.count(node))return oldNew[node];
        Node* copy = new Node(node->val);
        oldNew[node] = copy;

        for(Node* nei: node->neighbors){
            copy->neighbors.push_back(dfs(nei,oldNew));
        }
        return copy;
    }
};
