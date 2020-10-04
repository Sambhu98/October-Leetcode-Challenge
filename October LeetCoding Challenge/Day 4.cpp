class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        for (int i = 0; i < intervals.size(); i++)
        {
            bool f = 0;
            for (int j = 0; j < intervals.size(); j++)
            {
                if (i != j && intervals[j][0] <= intervals[i][0] && intervals[j][1] >= intervals[i][1])
                {f = 1; break;}
            }
            if (!f)
                ans.push_back(intervals[i]);
        }
        return (int)ans.size();
    }
};