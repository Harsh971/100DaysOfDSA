class Solution {
public:
    int dfs(int headId,vector<int>& informTime,vector<int> adj[]){

        int maxTime = 0;

        for(auto it:adj[headId])
           maxTime = max(maxTime,dfs(it,informTime,adj));

        return informTime[headId] + maxTime;   
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
            vector<int> adj[100005];

            for(int i=0;i<manager.size();i++)
                if(manager[i] != -1)
                  adj[manager[i]].push_back(i);
            
        return dfs(headID,informTime,adj);    
    }
};