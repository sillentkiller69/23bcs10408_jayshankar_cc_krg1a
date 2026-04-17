class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        return rec(arr, 0, n - 1, k, dp);
    }
    int mxele(vector<int>& arr, int i, int j) {
        int l = INT_MIN;
        for (int k = i; k <= j; k++) {
            l = max(l, arr[k]);
        }
        return l;
    }
    int temp = 0;
    int rec(vector<int>& arr, int i, int j, int& t, vector<vector<int>>& dp) {
        if (i > j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int temp = 0;
        for (int k = i; k < min(i + t, j + 1); k++) {
            int x = k - i + 1;
            if (x <= t) {
                int z = mxele(arr, i, k) * x + rec(arr, k + 1, j, t, dp);
                temp = max(temp, z);
            }
        }
        return dp[i][j] = temp;
    }
};