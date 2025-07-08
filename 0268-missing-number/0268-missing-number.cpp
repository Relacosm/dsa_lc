class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int t=(n*(n+1))/2;
        int o=accumulate(nums.begin(),nums.end(),0);
        return t-o;
    }
};