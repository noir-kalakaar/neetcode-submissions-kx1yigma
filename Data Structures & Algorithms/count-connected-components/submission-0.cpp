class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto&gg:edges){
            adj[gg[0]].push_back(gg[1]);
            adj[gg[1]].push_back(gg[0]);
        }
        vector<bool> visited(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
            dfs(i,adj,visited);
            ans++;
            }
        }
        return ans;
    }
    void dfs(int n, vector<vector<int>>&adj, vector<bool>&visited){
        if(visited[n])return;
        visited[n]=1;
        for(auto& nei:adj[n])dfs(nei,adj,visited);
        return;
    }
};
