#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int last_max = 0;
        int n = customers.size();
        int t = min(n, X);
        int all = 0;
        for (int i = 0; i < t; i++) {
            all += customers[i];
        }
        if (X > n) return all;

        for (int i = X; i < n; i++) {
            if (grumpy[i] == 0) {
                all += customers[i];
            }
        }

        int ans = all;
        for (int i = X; i < n; i++) {
            if (grumpy[i] == 1) {
                all += customers[i];
            }
            if (grumpy[i - X] == 1) {
                all -= customers[i - X];
            }
            if (all > ans) {
                ans = all;
            }
        }
        return ans;
    }
};


int main() {
    Solution sl;
    vector<int> customers = {1,0,1,2,1,1,7,5};
    vector<int> grumpy = {0,1,0,1,0,1,0,1};
    int X = 3;
    cout << sl.maxSatisfied(customers, grumpy, X) << endl;
    return 0;
}
