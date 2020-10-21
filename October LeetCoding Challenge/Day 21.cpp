class Solution {
public:
  vector<int> asteroidCollision(vector<int>& asteroids) {

    int i = 0;
    stack<int> st;
    while (i < asteroids.size())
    {
      if (asteroids[i] > 0)
      {
        st.push(asteroids[i]);
      }
      else
      {
        while (st.size() && st.top() > 0 && st.top() < abs(asteroids[i]))
          st.pop();

        if (st.size() && st.top() > 0 && st.top() == abs(asteroids[i]))
        { st.pop();
          i++;
          continue;
        }

        if (st.size() && st.top() > 0 && st.top() > abs(asteroids[i]))
        {
          i++;
          continue;
        }

        st.push(asteroids[i]);
      }
      i++;
    }
    vector<int> ans;
    while (st.size())
    {
      ans.push_back(st.top());
      st.pop();
    }
    reverse(ans.begin(), ans.end());

    return ans;



  }
};