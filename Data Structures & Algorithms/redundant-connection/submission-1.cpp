class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> res(2);
        int n = edges.size();
        vector<vector<int>> adj(n+1);
        
        for(auto& gg:edges){
            adj[gg[0]].push_back(gg[1]);
            adj[gg[1]].push_back(gg[0]);
            vector<bool> visited(n+1);
            if(dfs(gg[0],-1,adj,visited))return {gg[0],gg[1]};
        }
        
        return {};
    }
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited){
        if(visited[node]){
            return true;
        }
        visited[node] = 1;
        for(auto& nei:adj[node]){
            if(nei==parent)continue;
            if (dfs(nei,node,adj,visited)) return true;
        }
        return false;
    }
};
