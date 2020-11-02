class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {

        int ans = 0; int space = 0;
        vector<int> middle;
        vector<int> corner;
        bool flag = 0;
        for (int i = 0; i < seats.size(); i++)
        {
            if (seats[i] == 0)
                space++;
            else
            {
                if (flag && space)
                    middle.push_back(space), space = 0;
                else if (!flag && space)
                    corner.push_back(space), space = 0;

                flag = 1;
            }
        }
        if (space)
            corner.push_back(space);

        for (auto x : middle)
            ans = max(ans, (x + 1) / 2);

        for (auto x : corner)
            ans = max(ans, x);

        return ans;
    }
};