class Solution {
public:
  string removeDuplicateLetters(string s) {
    int last[26];
    bool vist[26];
    memset(vist, 0, sizeof(vist));
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
      last[s[i] - 'a'] = i;

    for (int i = 0; i < s.size(); i++)
    {
      if (vist[s[i] - 'a'])
        continue;

      while (!st.empty() && i < last[st.top() - 'a'] && st.top() > s[i])
      {
        vist[st.top() - 'a'] = false;
        st.pop();
      }

      st.push(s[i]);
      vist[s[i] - 'a'] = 1;
    }

    string res = "";
    while (!st.empty())
    {
      res += st.top();
      st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
  }
};