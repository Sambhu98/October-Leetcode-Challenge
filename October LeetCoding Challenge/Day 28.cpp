class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums)
    {
        vector<string> vs;
        if (!nums.size())
            return vs;

        vs.push_back(to_string(nums[0]));
        int j = 0;
        int i = 1;
        while (i < nums.size())
        {
            if (nums[i] - 1 == nums[i - 1])
            {
                string a = to_string(nums[j]);
                a += "->";
                a += to_string(nums[i]);

                vs[vs.size() - 1] = a;
            }
            else
            {
                j = i;
                vs.push_back(to_string(nums[i]));
            }
            i++;
        }

        return vs;

    }
};