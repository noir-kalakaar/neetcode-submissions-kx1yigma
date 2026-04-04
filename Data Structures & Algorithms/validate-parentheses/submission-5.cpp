class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n=s.size();
        st.push(s[0]);
        int i=1;
        while(i<n){
            char tmp='g';
            if(!st.empty()) tmp = st.top();
            if(s[i]=='{'||s[i]=='('||s[i]=='[')st.push(s[i]);
            else if((s[i]=='}'&& tmp=='{')||(s[i]==']'&& tmp=='[')||(s[i]==')'&& tmp=='('))st.pop();
            else return false;
            i++;
        }
        return st.empty();


    }
};
