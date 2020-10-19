class Solution {
public:
    int minRotation(vector<int>& A, vector<int>& B)
    {
        int ans = A.size() + 1;
        for (int dice = 1; dice <= 6; dice++)
        {
            int count = 0;
            int v = 0;
            for (int i = 0; i < A.size(); i++)
            {
                if (A[i] == dice)
                {++v; continue;}

                if (B[i] == dice)
                {++v; ++count;}
            }
            if (v == A.size())
                ans = min(ans, count);
        }

        if (ans == A.size() + 1)
            return -1;

        return ans;
    }
    int minDominoRotations(vector<int>& A, vector<int>& B) {

        int x = minRotation(A, B);
        int y = minRotation(B, A);

        int res = min(x, y);
        int res2 = max(x, y);

        if (res == -1)
            return res2;

        return res;

    }
};