class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int dp[n][n];
        string ans;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (j - i < 3)
                    dp[i][j] = (s[i] == s[j]);
                else dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1];
                if (dp[i][j] && (j - i + 1 > ans.size()))
                    ans = s.substr(i, j - i + 1);
            }
        }
        return ans;
    }
};