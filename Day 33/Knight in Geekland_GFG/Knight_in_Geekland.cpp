class Solution{
public:
    int knightInGeekland(int start_x,int start_y,vector<vector<int>> &arr){
        // Code here
        int n=arr.size();
        int m=arr[0].size();
        
        queue<pair<int,int>>q;
        q.push({start_x,start_y});
        vector<vector<int>>vis(n,vector<int>(m,0));
        vis[start_x][start_y]=1;
        
        vector<int>dx={1,1,-1,-1,2,2,-2,-2};
        vector<int>dy={2,-2,2,-2,1,-1,1,-1};
        vector<int>coins;
        
        while(!q.empty())
        {
            int size=q.size();
            int stepCoins=0;
            while(size--)
            {
                auto curr=q.front();
                q.pop();
                int x=curr.first;
                int y=curr.second;
                stepCoins+=arr[x][y];
                for(int i=0; i<8; i++)
                {
                    int new_x=x+dx[i];
                    int new_y=y+dy[i];
                    if(new_x>=0 and new_y>=0 and new_x<n and new_y<m and !vis[new_x][new_y])
                    {
                        q.push({new_x,new_y});
                        vis[new_x][new_y]=1;
                    }
                }
                
            }
            coins.push_back(stepCoins);
        }
        
        int ans=-1;
        int max_coin=INT_MIN;
        
        int coinsSize=coins.size();
        for(int i=coinsSize-1; i>=0 ; i--)
        {
            if(i+coins[i]<coinsSize)
            {
                coins[i]+=coins[i+coins[i]];
            }
            
            if(coins[i]>=max_coin)
            {
                ans=i;
                max_coin=coins[i];
            }
        }
        
        return ans;
    }
};