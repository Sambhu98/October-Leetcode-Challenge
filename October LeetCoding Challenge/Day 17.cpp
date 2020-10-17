class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
        map<string, int> mp;
        for (int i = 0; i + 9 < s.length(); i++)
        {
            string str = s.substr(i, 10);
            mp[str]++;
        }
        for (auto v : mp)
            if (v.second > 1)
                ans.push_back(v.first);

        return ans;
    }
};