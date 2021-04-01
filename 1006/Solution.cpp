#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int clumsy(int N) {
        vector<char> ops = {'*', '/', '+', '-'};
        vector<int> nums;
        vector<char> op_arr;
        int op_idx = 0;
        int pre = N;
        for (int i = N - 1; i > 0; i--) {
            char op = ops[op_idx++];
            op_idx = op_idx % 4;
            if (op == '*') {
                pre *= i;
            } else if (op == '/') {
                pre /= i;
            }

            if (op == '+' || op == '-') {
                nums.push_back(pre);
                op_arr.push_back(op);
                pre = i;
            }

            if (i == 1) nums.push_back(pre);
        }
        if (nums.size() == 0) return pre;
        pre = nums[0];
        int j = 0;
        for (int i = 1; i < nums.size(); i++) {
            char op = op_arr[j++];
            if (op == '+') {
                pre += nums[i];
            } else {
                pre -= nums[i];
            }
        }
        return pre;
    }
};

int main() {
    Solution sl;
    cout << sl.clumsy(4) << endl;
    cout << sl.clumsy(10) << endl;
    return 0;
}
