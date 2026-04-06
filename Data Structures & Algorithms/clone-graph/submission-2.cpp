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
        if(!node)return nullptr;
        unordered_map<Node*,Node*> mp;
        queue<Node*> q;
        q.push(node);
        mp[node] = new Node(node->val);

        while(!q.empty()){
            Node* cur = q.front();
            q.pop();
            for(auto gg:cur->neighbors){
                if(!mp.count(gg)){
                    mp[gg] = new Node(gg->val);
                    q.push(gg);
                }
                mp[cur]->neighbors.push_back(mp[gg]);
            }
        }
        return mp[node];
    }
    
};
