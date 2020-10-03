class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        map<int, int> mp;
        set<pair<int, int>> st;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int x = nums[i];
            int y = nums[i] - k;
            if (mp[y] && st.find({y, x}) == st.end())
            {st.insert({y, x}); ans++;}
            mp[x]++;
        }

        return ans;
    }
};