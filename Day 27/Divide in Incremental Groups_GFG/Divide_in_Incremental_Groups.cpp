class Solution {
  public:
    vector<vector<vector<int>>>dp;
    int solve(int sum_left, int count, int prev)
    {
        if(count==0)
        {
            if(sum_left==0)
            {
                return 1;
            }
            return 0;
        }
        
        if(sum_left==0)
        {
            return 0;
        }
        if(dp[sum_left][prev][count]!=-1)return dp[sum_left][prev][count];
        
        
        int ways=0;
        for(int i=prev; i<=sum_left; i++)
        {
            ways+=solve(sum_left-i,count-1,i);
        }
        
        return dp[sum_left][prev][count]= ways;
    }
    
    int countWaystoDivide(int N, int K) {
        // Code here
        dp=vector<vector<vector<int>>>(N+1,vector<vector<int>>(N+1,vector<int>(K+1,-1)));
        return solve(N, K, 1 );
    }
};