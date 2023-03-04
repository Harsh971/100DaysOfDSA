int answer;
pair<int,int> dfs(int node, vector<vector<int>>&tree, vector<int> &A){
    int x,y;
    x=y=-1e9;
    
    if(tree[node].size() == 0) {
        x = A[node];
        y = A[node]* -1;
    }
    for(auto child : tree[node]){
        pair<int,int>ans = dfs(child, tree, A);
        x = max(x, A[node] + ans.second);
        y = max(y, A[node] * -1 + ans.first);
    }
    answer = max(answer, x);
    
    return {x,y};
}

class Solution {
  public:
    long long bestNode(int N, vector<int> &A, vector<int> &P) {
        vector<vector<int>> tree(N);
        
        for(int i=1; i<N; i++)
        {
            tree[P[i]-1].push_back(i);
        }
        answer = -1e9;
        dfs(0, tree, A);
        
        return answer;
        
    }
};