class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        unordered_set<int> visited;

        for(auto& edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        if(!dfs(0,-1,adj,visited))return false;
        return visited.size()==n;

        
    }
    bool dfs(int node, int parent, vector<vector<int>>& adj, unordered_set<int>& visited){
        if(visited.count(node))return false;
        
        visited.insert(node);
        for(auto& gg:adj[node]){
            if(gg==parent)continue;
            if(!dfs(gg,node,adj,visited))return false;
        }
        return true;
        
    }
};
