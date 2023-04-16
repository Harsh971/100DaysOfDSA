class Solution {
 public:
  int maxValueOfCoins(vector<vector<int>>& piles, int k) {
    // dp[i][k] := max value of picking k coins from piles[i:]
    dp.resize(piles.size(), vector<int>(k + 1));
    return maxValueOfCoins(piles, 0, k);
  }

 private:
  vector<vector<int>> dp;

  int maxValueOfCoins(const vector<vector<int>>& piles, int i, size_t k) {
    if (i == piles.size() || k == 0)
      return 0;class Solution {
public:
    int numWays(vector<string>& A, string target) {
        long mod = 1e9+7, M = A.size(), L = A[0].size(), N = target.size();
        if (L < N) return 0;
        vector<array<long, 26>> cnt(L, array<long, 26>());
        for (int i = 0; i < L; ++i) {
            for (int j = 0; j < M; ++j) cnt[i][A[j][i] - 'a']++;
        }
        vector<vector<int>> dp(L + 1, vector<int>(N + 1));
        for (int i = 0; i < L; ++i) {
            dp[i][0] = 1;
            for (int j = 0; j <= i && j < N; ++j) {
                dp[i + 1][j + 1] = ((cnt[i][target[j] - 'a'] * dp[i][j]) % mod + dp[i][j + 1]) % mod;
            }
        }
        return dp[L][N];
    }
};