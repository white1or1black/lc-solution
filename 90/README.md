## 90. [子集 II](https://leetcode-cn.com/problems/subsets-ii/)

*题目描述*

>给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。
>
>解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。
>
> 
>
>示例 1：
>
>输入：nums = [1,2,2]
>输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]
>示例 2：
>
>输入：nums = [0]
>输出：[[],[0]]
>
>
>提示：
>
>1 <= nums.length <= 10
>-10 <= nums[i] <= 10
>
>来源：力扣（LeetCode）
>链接：https://leetcode-cn.com/problems/subsets-ii



*题解1： *递归*

>递归遍历所有可能性，排序去重
>
>```c++
>
>    vector<vector<int>> res;
>    int len;
>    void recur(int idx, vector<int>& nums, vector<int>& comb) {
>        res.push_back(comb);
>        if (idx == len) return;
>        for (int i = idx; i < len; i++) {
>          	// 非当前元素，并且和前一个元素相等会造成重复计算，此处跳过去重
>            if (i != idx && nums[i] == nums[i - 1]) continue;
>            comb.push_back(nums[i]);
>            recur(i + 1, nums, comb);
>            comb.pop_back();
>        }
>    }
>
>    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
>        len = nums.size();
>        vector<int> comb;
>      	// 排序，方便去重
>        sort(nums.begin(), nums.end());
>        recur(0, nums, comb);
>        return res;
>    }
>
>```
>
>排序的时间复杂度为O(n*lg(n)),递归的时间复杂度为O(n * 2^n), 所以时间复杂度为O(n * 2^n); 临时数组和递归栈的空间复杂度都是O(n), 所以时间复杂度为O(n)。





