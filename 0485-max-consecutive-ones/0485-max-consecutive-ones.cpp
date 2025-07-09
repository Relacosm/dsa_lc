class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int c=0;
        int maxc=0;
        for(int ch:nums){
            if(ch==1){
                c++;
                maxc=max(maxc,c);
            }
            else{
                c=0;
            }
        }
        return maxc;

    }
};