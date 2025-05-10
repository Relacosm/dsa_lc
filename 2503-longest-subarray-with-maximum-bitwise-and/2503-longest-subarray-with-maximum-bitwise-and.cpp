class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxValue = *std::max_element(nums.begin(), nums.end());
    
    // Step 2: Traverse the array to find the length of the longest subarray where all elements are `maxValue`
    int longestLength = 0;
    int currentLength = 0;
    
    for (int num : nums) {
        if (num == maxValue) {
            currentLength++;
        } else {
            longestLength = std::max(longestLength, currentLength);
            currentLength = 0;
        }
    }
    
    // Final check in case the longest subarray ends at the last element
    longestLength = std::max(longestLength, currentLength);
    
    return longestLength;
    }
};