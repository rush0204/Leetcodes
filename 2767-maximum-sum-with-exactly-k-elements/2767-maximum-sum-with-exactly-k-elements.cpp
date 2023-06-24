class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int max = INT_MIN;
        int maxsize = 0;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]>max){
                max = nums[i];
            }
        }
    for(int i = 0;i<k;i++){
     maxsize+=max;
     max++;
    }
     return maxsize;
    }
   
};