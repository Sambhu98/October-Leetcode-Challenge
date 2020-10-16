class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (!matrix.size())
            return false;

        int r = matrix.size();
        int c = matrix[0].size();
        int l = 0, h = r - 1;
        while (l + 1 < h)
        {
            int mid = (l + h) / 2;
            if (matrix[mid][0] <= target)
                l = mid;
            else
                h = mid;
        }
        for (int i = 0; i < c; i++)
            if (matrix[l][i] == target || matrix[h][i] == target)
                return true;

        return false;

    }
};