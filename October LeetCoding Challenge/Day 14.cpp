class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n <= 3)
            return *max_element(nums.begin(), nums.end());

        int dp[n - 1];
        int dp2[n - 1];
        memset(dp, 0, sizeof(dp));
        memset(dp2, 0, sizeof(dp2));

        dp[0] = nums[0];
        dp[1] = max(nums[1], nums[0]);
        for (int i = 2; i < n - 1; i++)
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);

        // for(int i=0;i+1<n;i++)
        //     cout<<dp[i]<<" ";
        // cout<<endl;

        dp2[0] = nums[1];
        dp2[1] = max(nums[2], nums[1]);
        for (int i = 2; i < n - 1; i++)
            dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i + 1]);

        // for(int i=0;i+1<n;i++)
        //     cout<<dp2[i]<<" ";
        // cout<<endl;

        return max(dp[n - 2], dp2[n - 2]);

    }
};