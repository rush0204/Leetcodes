class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int h = 0;
        string s1 = ""; 
        for(int i = s.length()-1;i>=0;i--){
            if(s[i]=='#'){
                h++;
            }
            if(h==0){
                s1 = s[i] + s1;
            }
            else{
                if(s[i]!='#'){
                    h--;
                }
            }
        }
        int h1 = 0;
        string t1 = "";
         for(int i = t.length()-1;i>=0;i--){
            if(t[i]=='#'){
                h1++;
            }
            if(h1==0){
                t1 = t[i] + t1;
            }
            else{
                if(t[i]!='#'){
                    h1--;
                }
            }
        }
        return s1==t1;
    }
};
// class Solution {
// public:
//     bool backspaceCompare(string s, string t) {
//         int h = 0;
//         string s1 = "";
//         string t1 = "";
        
//         for (int i = s.length() - 1; i >= 0; i--) {
//             if (s[i] == '#') {
//                 h++;
//             }
//             if (h == 0) {
//                 s1 = s[i] + s1;
//             } else if (s[i] != '#') {
//                 h--;
//             }
//         }

//         int h1 = 0;
//         for (int i = t.length() - 1; i >= 0; i--) {
//             if (t[i] == '#') {
//                 h1++;
//             }
//             if (h1 == 0) {
//                 t1 = t[i] + t1;
//             } else if (t[i] != '#') {
//                 h1--;
//             }
//         }

//         return s1 == t1;
//     }
// };
