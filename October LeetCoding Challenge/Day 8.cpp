class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1;
        while (l + 1 < h)
        {
            int mid = (l + h) / 2;
            if (nums[mid] <= target)
                l = mid;
            else
                h = mid;
        }

        if (nums[l] == target)
            return l;
        else if (nums[h] == target)
            return h;
        else
            return -1;
    }
};