class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<string> st;
        int ans=0;
        for(string i:operations){
            if(i!="+" && i!="C" && i!="D")st.push(i);
            else if(i=="+"){
                int t1,t2;
                t1=stoi(st.top());
                st.pop();
                t2=stoi(st.top());
                int t3 = t1+t2;
                st.push(to_string(t1));
                st.push(to_string(t3));
            }
            else if(i=="C"){
                st.pop();
            }
            else if(i=="D"){
                int t=2*stoi(st.top());
                st.push(to_string(t));
            }
        }
        int g;
        while(!st.empty()){
            g = stoi(st.top());
            st.pop();
            ans+=g;
        }
        return ans;
    }
};