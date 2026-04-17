class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < m + 1; j++) {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
            }
        }
        string ans = "";
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                if (s1[i - 1] == s2[j - 1]) {

                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {

                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        int i = n, j = m;
        string lcs = "";

        // Traverse dp table from bottom-right to top-left
        while (i > 0 && j > 0) {
            if (s1[i - 1] == s2[j - 1]) {
                // Characters match, add to result and move diagonally
                lcs += s1[i - 1];

                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {

                lcs += s1[i - 1];
                i--;
            } else {
                lcs += s2[j - 1];

                j--;
            }
        }
        while (j--) {
            lcs += s2[j];
        }
        while (i--) {
            lcs += s1[i];
        }

        // Reverse string since it was built backwards
        reverse(lcs.begin(), lcs.end());

        return lcs;
    }
};