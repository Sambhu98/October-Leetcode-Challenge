class Solution {
public:
    int dp[1005][1005][2];
    int maxlabh(vector<int>&p, int indx, int s, bool f)
    {
        if (indx >= p.size() || s <= 0)
            return 0;

        if (dp[indx][s][f] != -1)
            return dp[indx][s][f];

        int ans = maxlabh(p, indx + 1, s, f);
        if (f)
            ans = max(ans, p[indx] + maxlabh(p, indx + 1, s - 1, 0));
        else
            ans = max(ans, -p[indx] + maxlabh(p, indx + 1, s, 1));

        return dp[indx][s][f] = ans;
    }
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() < 2 || k == 0)
            return 0;

        int n = prices.size();
        if (k > n / 2)
        {
            int ans = 0;
            for (int i = 1; i < prices.size(); i++)
                ans += (max(0, prices[i] - prices[i - 1]));

            return ans;
        }

        memset(dp, -1, sizeof(dp));

        return maxlabh(prices, 0, k, 0);
    }
};