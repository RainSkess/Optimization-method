class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        //只有一个元素返回false
        if (nums.size() == 1) return false;

        unordered_set<int> hash;
        for (int i = 0; i < nums.size(); ++i)
        {
            //先找，找到直接返回true，没找到存到hash中
            if (hash.count(nums[i])) return true;
            hash.insert(nums[i]);
        }
        //循环结束，没找到返回false
        return false;
    }
};