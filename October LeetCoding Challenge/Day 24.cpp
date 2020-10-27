class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {

        sort(tokens.begin(), tokens.end());
        int score = 0;
        int ans = 0;
        int i = 0;
        int j = tokens.size() - 1;
        while (i <= j && score >= 0)
        {
            if (tokens[i] <= P) {
                P -= tokens[i];
                i++;
                ans = max(ans, ++score);
            }
            else
            {
                P += tokens[j];
                j--;
                score--;
            }
        }

        return ans;
    }
};