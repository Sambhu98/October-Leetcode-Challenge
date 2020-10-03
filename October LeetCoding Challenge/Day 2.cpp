class Solution {
public:
    int dp[35][505];
    vector<vector<int>> ans;
    void findcombination(int indx, vector<int>& c, int t, int s, vector<int> temp)
    {
        for (auto x : temp)
            cout << x << " ";
        cout << endl;

        if (s > t || indx >= c.size())
            return;

        if (s == t)
        {
            ans.push_back(temp);
            return;
        }

        for (int i = indx; i < c.size(); i++)
        {
            temp.push_back(c[indx]);
            findcombination(i + 1, c, t, s + c[indx], temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        memset(dp, -1, sizeof(dp));
        vector<int> temp;
        findcombination(0, candidates, target, 0, temp);
        return ans;
    }
};