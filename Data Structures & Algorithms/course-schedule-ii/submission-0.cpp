class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> visited(numCourses,0);
        for(auto& gg:prerequisites){
            adj[gg[0]].push_back(gg[1]);
        }
        vector<int> res;
        for(int i=0;i<numCourses;i++){
            if(!dfs(i,res,adj,visited))return {};
        }
        // reverse(res.begin(),res.end());
        return res;
    }
    bool dfs(int node, vector<int>& res, vector<vector<int>>& adj, vector<int>& visited){
        if(visited[node]==1)return false;
        if(visited[node]==2)return true;
        visited[node]=1;
        for(auto& gg:adj[node]){
            if(!dfs(gg,res,adj,visited))return false;
        }
        res.push_back(node);
        visited[node]=2;
        return true;
    }
};
