class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int start = 0;
        
       
        for(int i = 0;i<s.length();i++){
            map<char,int> check;
            int currLen = 0;
            for(int j = i;j<s.length();j++){
            check[s[j]]++;
           if(check[s[j]]>1){
               break;
           }
           else{
               currLen++;
           }
            }
            if(currLen>maxLen){
                maxLen = currLen;
            }
        }
        return maxLen;
    }
};

