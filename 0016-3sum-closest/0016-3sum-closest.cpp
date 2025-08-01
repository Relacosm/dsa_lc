class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int result=nums[0]+nums[1]+nums[2];
        for(int i=0;i<nums.size()-2;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int left=i+1;
            int right=nums.size()-1;
            while(left<right){
                int sum=nums[i]+nums[left]+nums[right];
                int c=target-sum;
                if(abs(c)<abs(target-result)){
                    result=sum;
                }
                if(sum<target) left++;
                else if(sum>target) right--;
                else return sum;
            }
        }
        return result;
    }
};