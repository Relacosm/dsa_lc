class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
           int c=target-nums[i];
           if(map.find(c)!=map.end()){
            return{map[c],i};
           }
           map[nums[i]]=i;
        }
        return{};
    }
};