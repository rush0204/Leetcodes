class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      map<char,int> check;
      int start = -1;
      int maxLen = 0;
      for(int i =0;i<s.length();i++){

          if(check.count(s[i])!=0){
              start = max(start,check[s[i]]);
          }
          check[s[i]] = i;
          maxLen = max(maxLen,i-start);

      }
      return maxLen;
    }
};

