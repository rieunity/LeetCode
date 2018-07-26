class Solution {
public:
    string longestPalindrome(string s) {
        int j = 0;
        int k = 0;
        int n = s.size();
        if (n == 0) return "";
        if (n == 1) return s;
        for (int i = 0; i < n; i++) {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = 0;
            if ((i < n - 1) && (s[i] == s[i+1]))
                len2 = expandAroundCenter(s, i, i+1);
            int len = len1 > len2 ? len1 : len2;
            if(len > k - j + 1) {
                k = i + len / 2;
                j = i - (len - 1) / 2;
            }
        }
        return s.substr(j, k - j + 1);
    }
    int expandAroundCenter(string s, int j, int k) {
        int l = j;
        int r = k;
        while ((l >= 0) && (r >= 0) && s[l] == s[r]) {
            l--;
            r++;
        }
        return r - l - 1;
    }
};