class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1;
        stack<char> st2;
        for(int i = 0;i<s.length();i++){
            if(s[i]!='#'){
                st1.push(s[i]);
            }
            if(s[i]=='#'){
                if(!st1.empty()) st1.pop();
            }
        }
          for(int i = 0;i<t.length();i++){
            if(t[i]!='#'){
                st2.push(t[i]);
            }
            if(t[i]=='#'){
                 if(!st2.empty())  st2.pop();
            }
        }
        bool ans = true;
        while(!st1.empty()&&!st2.empty()){
            if(st1.top()==st2.top()){
                st1.pop();
                st2.pop();
            }
            else { cout<<st1.top()<<" "<<st2.top(); ans = false; break;}
        }
        if(!st1.empty()&&st2.empty()) return false;
          if(st1.empty()&&!st2.empty()) return false;
        return ans;
    }
};