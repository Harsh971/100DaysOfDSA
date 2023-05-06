int dp[101][1001][101];
class Solution {
  public:
    bool makeChanges(int N, int K, int target, vector<int> &coins) {
        for(int i = 0; i < N + 1; i++){
            for(int j = 0; j < target + 1; j++){
                for(int k = 0;k < K + 1; k++){
                    if(i == 0){
                        dp[i][j][k] = j == 0 and k == 0;
                        continue;
                    }
                    
                    int x, y;
                    x = y = 0;
                    
                    x = dp[i - 1][j][k];
                    if(j >= coins[i - 1] and k)
                        y = dp[i][j - coins[i - 1]][k - 1];
                    
                    dp[i][j][k] = x + y;
                }
            }
        }
        
        return dp[N][target][K];
    }
};