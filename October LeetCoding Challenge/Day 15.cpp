class Solution {
public:
    void rotate(vector<int>& nums, int k)
    {
        vector<int> v = nums;

        v.insert(v.end(), nums.begin(), nums.end());
        k %= nums.size();
        int n = nums.size() - k;

        int j = 0;
        for (int i = n; i < n + (int)nums.size(); i++)
            nums[j++] = (v[i]);

    }
};