You can find the problem statement here: https://leetcode.com/problems/house-robber/

class Solution {
public:
    int rob(vector<int>& nums) {
        // Base case
        if (nums.size() == 0) return 0;
        if (nums.size() == 1) return nums[0];
        
        // Initialize dp array
        // dp[i] represents the maximum amount of money that can be robbed from houses [0, i]
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        // Fill in dp array
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
        }
        
        // Return the maximum amount of money that can be robbed from all houses
        return dp[nums.size() - 1];
    }
};
