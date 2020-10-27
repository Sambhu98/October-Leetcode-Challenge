class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, 0);

        for (int i = 1; i <= sqrt(n); i++)
            dp[i * i] = true;


        for (int i = 1; i <= n; i++)
        {
            if (dp[i] == true)
                continue;

            for (int j = 1; j <= sqrt(i); j++)
            {   if (dp[i - (j * j)] == false)
                    dp[i] = true;
            }
        }

        // for(auto x: dp)
        //     cout<<x<<" ";


        return dp[n];

    }
};