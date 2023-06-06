class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        if(n==1||n==2||n==0){
            return true;
        }
       for(int i = 0;i<n-2;i++){
           if(arr[i]-arr[i+1]!=arr[i+1]-arr[i+2]){
              return false;
           }
       }
        return true;
    }
};