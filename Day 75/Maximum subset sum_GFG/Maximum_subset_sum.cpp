class Solution {

  public:
    long long findMaxSubsetSum(int N, vector<int> &A) {
        vector<vector<int>> dp(N + 1, vector<int> (2, 0));
        
        for(int i = 1; i < N + 1; i++){
            int x, y;
            x = y = 0;
            
            x = A[i - 1] + dp[i - 1][0]; // take the current element
            y = dp[i - 1][1]; // do not take current element
            
            dp[i][1] = x;
            dp[i][0] = max(x, y);
        }
        
        return dp[N][0];
    }
};