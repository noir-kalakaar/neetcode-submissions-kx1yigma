class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& a) {
        int n = a.size();
        stack<int> st,st1;
        vector<int> res(n,0);
        st.push(a[n-1]);
        st1=st;
        for(int i=n-2;i>=0;i--){
            int temp = 0;
            while(!st.empty() && a[i]>=st.top()){
                st.pop();
                temp++;
            }
            if(st.empty())res[i]=0;
            else {res[i]=temp+1;
                st = st1;
            }

            st.push(a[i]);
            st1.push(a[i]);
        }
        return res;
    }
};
