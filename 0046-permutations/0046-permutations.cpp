class Solution {
public:
void rec(vector<int>& nums, vector<int> ds, vector<vector<int>>& ans, vector<int> mp){
    if(ds.size()==nums.size()) { ans.push_back(ds);  return;}
  for(int i = 0;i<nums.size();i++){
      if(!mp[i]){
        mp[i] = 1;
        ds.push_back(nums[i]);
        rec(nums,ds,ans,mp); 
        mp[i] = 0;
        ds.pop_back();
      }     
}

}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
        vector<int>  mp(nums.size(),0);
        for(int i = 0;i<nums.size();i++){
mp[i] = 1;
ds.push_back(nums[i]);
rec(nums,ds,ans,mp);   
mp[i] = 0;
ds.pop_back();    
}

        return ans;
    }
};