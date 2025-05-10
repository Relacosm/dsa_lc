class Solution {
public:
    int maximumProduct(std::vector<int>& nums) {
    // Sort the array
    std::sort(nums.begin(), nums.end());

    int n = nums.size();

    // The maximum product can be:
    // 1. The product of the largest three numbers
    // 2. The product of the two smallest numbers (if negative) and the largest number
    int option1 = nums[n-1] * nums[n-2] * nums[n-3];
    int option2 = nums[0] * nums[1] * nums[n-1];

    return std::max(option1, option2);
}
};