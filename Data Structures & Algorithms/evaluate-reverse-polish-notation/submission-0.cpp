class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int res=0;
        for(auto i:tokens){
            if(i=="+"){
                int t1=st.top();
                st.pop();
                int t2=st.top();
                st.pop();
                st.push(t1+t2);
            }
            else if(i=="*"){
                int t1=st.top();
                st.pop();
                int t2=st.top();
                st.pop();
                st.push(t1*t2);
            }
            else if(i=="-"){
                int t1=st.top();
                st.pop();
                int t2=st.top();
                st.pop();
                st.push(t2-t1);
            }
            else if(i=="/"){
                int t1=st.top();
                st.pop();
                int t2=st.top();
                st.pop();
                st.push(t2/t1);
            }
            else st.push(stoi(i));
        }
        return st.top();
    }
};
