class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() != B.size())
            return false;

        int freq[26];
        bool check = false;
        int c = 0;
        memset(freq, 0, sizeof(freq));
        vector<pair<char, char>> v;
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] != B[i])
            {v.push_back({A[i], B[i]}); ++c;}
            else
                freq[A[i] - 'a']++;

            if (freq[A[i] - 'a'] >= 2)
                check = true;
        }

        if ((check && c == 0))
            return true;

        if (c == 2 && v[0].first == v[1].second && v[0].second == v[1].first)
            return true;

        return false;
    }
};