class Solution {
  public:
    int unvisitedLeaves(int N, int leaves, int frogs[]) {
        // Code here
        vector<int>vis(leaves+1,0);
        
        for(int i=0;i<N; i++)
        {
            int st=frogs[i];
            if(st<=leaves and  !vis[st])
            {
                for(int j=st; j<=leaves; j+=st)
                {
                    vis[j]=1;
                }
            }
            
        }
        
        int ans=0;
        for(int i=1; i<=leaves; i++)
        {
            if(vis[i]==0)ans++;
        }
        
        return ans;
    }
};