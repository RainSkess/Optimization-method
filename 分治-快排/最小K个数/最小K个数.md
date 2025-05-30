[最小K个数]: https://leetcode.cn/problems/smallest-k-lcci/



```c++
class Solution {
public:

    void quick_sort(vector<int>& nums, int left, int right, int k)
    {
        if (left >= right) return;
        // 随机选择基准元素
        int key = nums[rand() % (right - left + 1) + left];
        // 数组分三块
        int i = left, l = left - 1, r = right + 1;
        while (i < r)
        {
            if (nums[i] < key) swap(nums[++l], nums[i++]);
            else if (nums[i] == key) ++i;
            else swap(nums[--r], nums[i]);
        }
        // [left, l] [l + 1, r - 1] [r, right]
        int less_count = l - left + 1, equal_count = r - 1 - l;
        if (less_count > k) quick_sort(nums, left, l, k);
        else if (less_count + equal_count >= k) return;
        else quick_sort(nums, r, right, k - less_count - equal_count);
    }

    vector<int> smallestK(vector<int>& arr, int k) {
        srand(time(NULL));
        quick_sort(arr, 0, arr.size() - 1, k);
        return {arr.begin(), arr.begin() + k};
    }
};
```

