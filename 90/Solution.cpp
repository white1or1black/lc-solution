#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;


class Solution {
public:
    vector<vector<int>> res;
    int m, n;
    int len;
    void dfs(int idx, vector<int>& nums, vector<int>& comb) {
        res.push_back(comb);
        if (idx == len) return;
        for (int i = idx; i < len; i++) {
            if (i != idx && nums[i] == nums[i - 1]) continue;
            comb.push_back(nums[i]);
            dfs(i + 1, nums, comb);
            comb.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        len = nums.size();
        vector<int> comb;
        sort(nums.begin(), nums.end());
        dfs(0, nums, comb);
        return res;
    }
};


int main() {
    Solution sl;
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> res = sl.subsetsWithDup(nums);
    for (vector<int> line: res) {
        for (int item: line) {
            cout << item << " ";
        }
        cout << endl;
    }
}
