class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& a) {
        int n = a.size();
        stack<pair<int,int>> st;
        vector<int> res(n,0);
        for(int i=0;i<n;i++){
            while(!st.empty() && a[i]>st.top().first){
                auto gg = st.top();
                st.pop();
                res[gg.second] = i - gg.second;
            }
            st.push({a[i],i});
        }
        return res;
        
    }
};
