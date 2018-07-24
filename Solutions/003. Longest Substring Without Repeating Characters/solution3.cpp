class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int* a = new int[257]();
        int ans = 0;
        int n = s.size();
        for (int j = 0, i = 0; j < n; j++) {
            i = i > a[s[j]] ? i : a[s[j]];
            ans = ans > j - i +1 ? ans : j - i + 1;
            a[s[j]] = j + 1;
        }
        return ans;
    }
};