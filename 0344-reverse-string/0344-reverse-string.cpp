class Solution {
public:
    void reverseString(vector<char>& s) {
    int j = 0;
        for(int i = s.size()-1;i>j;i--){
           char p = s[j];
           s[j] = s[i];
           s[i] = p;
           j++;
        }
    }
};