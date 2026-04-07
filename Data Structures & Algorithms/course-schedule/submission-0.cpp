class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> visited(numCourses,0);

        for(auto& a:prerequisites){
            adj[a[0]].push_back(a[1]);
        }
        vector<int> res;
        for(int i=0;i<numCourses;i++){
            if(visited[i]==0){
                if(!dfs(i,res,adj,visited))return false;
            }
        }
        reverse(res.begin(),res.end());
        return true;
    }
    bool dfs(int node, vector<int>& res, vector<vector<int>>& adj, vector<int>& visited){
        if(visited[node]==1)return false;
        if(visited[node]==2)return true;
        visited[node]=1;
        for(auto& gg:adj[node]){
            if(!dfs(gg,res,adj,visited))return false;
        }
        visited[node]=2;
        res.push_back(node);
        return true;
    }
};

