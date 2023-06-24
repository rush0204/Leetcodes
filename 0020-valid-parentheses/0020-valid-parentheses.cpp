class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0;i<s.length();i++){
            if(s[i]=='}'){
             if(st.empty()) return false;
                if(st.top()!='{') return false;
                    st.pop();
            }
            else if(s[i]==']'){
                if(st.empty()) return false;
                if(st.top()!='[') return false;
                    st.pop();
            }
            else if(s[i]==')'){
             if(st.empty()) return false;
                if(st.top()!='(') return false;
                    st.pop();
            }
            else st.push(s[i]);
        }
        return st.empty();
    }
};