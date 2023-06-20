class Solution {
public:
map<int,int> map;
    vector<int> twoSum(vector<int>& nums, int target) 
    {
         vector<int> p;
       for(int i = 0;i<nums.size();i++){
           int k = target - nums[i];
           if(map.count(k)){
               p.push_back(map[k]);
                p.push_back(i);
               break;
           }
           map[nums[i]] = i;
       }
     return p;  
    }
       
};