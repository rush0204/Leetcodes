class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1){
            return 0;
        }
        int farthest = 0;
        int jump = 0;
        int current = 0;
        for(int i = 0;i<nums.size()-1;i++){
             int far = nums[i]+i;
             farthest = max(far,farthest);
            if(current==i){
                current = farthest;
                jump++;
            }
        }
        return jump;
    }
};