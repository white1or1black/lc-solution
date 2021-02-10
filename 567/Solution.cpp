#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    bool isEqual(vector<int>& target, vector<int>& source) {
        for (int i = 0; i < 26; i++) {
            if (target[i] != source[i]) return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        vector<int> target(26, 0);
        vector<int> source(26, 0);
        for (char c: s1) {
            int t = c - 'a';
            target[t]++;
        }
        int m = s1.size();
        int n = s2.size();
        if (m > n) return false;
        for (int i = 0; i < n; i++) {

            if (i < m) {
                int t = s2[i] - 'a';
                source[t]++;
                if (i == m - 1 && isEqual(target, source)) return true;
            } else {
                int cur = s2[i] - 'a';
                int pre = s2[i - m] - 'a';
                source[cur]++;
                source[pre]--;
                if (isEqual(target, source)) return true;
            }

        }
        return false;
    }
};


int main() {
    Solution sl;
    cout << sl.checkInclusion("ab", "eidbaooo") << endl;
    cout << sl.checkInclusion("ab", "eidboaoo") << endl;
    return 0;
}
