class Solution{
    public:
        vector<int> updateQuery(int N,int Q,vector<vector<int>> &U)
        {
            vector<vector<int>> start(N), finish(N);
            for(auto query : U)
            {
                start[query[0]-1].push_back(query[2]);
                finish[query[1]-1].push_back(query[2]);
            }
            vector<vector<int>> answer(N, vector<int> (32,0));
            
            for(int i=0; i<N; i++)
            {
                for(auto num : start[i])
                {
                    for(int j=0; j<32; j++)
                    {
                        answer[i][j] += (num >> j) & 1;
                    }
                }
                if(i>0)
                {
                    for(int j=0; j<32; j++)
                    {
                        answer[i][j] += answer[i-1][j];
                    }
                    for(auto num : finish[i-1])
                    {
                        for(int j=0; j<32; j++)
                        {
                            answer[i][j] -= (num >> j) & 1;
                        }
                    }
                }
            }
            vector<int> ans(N);
            
            for(int i=0; i<N; i++)
            {
                int value = 0;
                for(int j=0; j<32; j++)
                {
                    if(answer[i][j] > 0)
                    {
                        value += (1 << j);
                    }
                }
                ans[i] = value;
            }
            return ans;
        }
};