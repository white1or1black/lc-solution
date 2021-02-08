#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 1;
        int ans = 0;
        int cnt = 1;
        for (int  i = 1; i < n - 1; i++) {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1] ||
                arr[i] < arr[i - 1] && arr[i] < arr[i + 1]
            ) {
                cnt++;
            } else {
                if (arr[i] > arr[i - 1] || arr[i] < arr[i - 1]) {
                    cnt++;
                }
                if (cnt > ans) ans = cnt;
                cnt = 1;
            }
        }
        if (n > 2) {
            if (arr[n - 2] > arr[n - 1] && arr[n - 2] > arr[n - 3] ||
            arr[n - 2] < arr[n - 1] && arr[n - 2] < arr[n - 3]) {
                cnt++;
            }
        } else {
            if (arr[n - 1] != arr[n - 2]) cnt++;
        }
        ans = max(ans, cnt);
        return ans;
    }
};

int main() {
    Solution sl;
    vector<int> arr = { 9,4,2,10,7,8,8,1,9 };
    cout << sl.maxTurbulenceSize(arr) << endl;
    return 0;
}
