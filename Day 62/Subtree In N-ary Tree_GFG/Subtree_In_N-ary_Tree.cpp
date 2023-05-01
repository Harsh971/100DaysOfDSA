class Solution{
public:
    int duplicateSubtreeNaryTree(Node *root){
        map<vector<int>, int> f;
        
        function<vector<int>(Node *)> dfs = [&](Node * node) -> vector<int> {
            vector<int> current = { node -> data, -1 };
            
            for(auto child : node -> children){
                vector<int> next = dfs(child);
                for(auto i : next)
                    current.push_back(i);
            }
            
            current.push_back(-1);
            
            ++f[current];
            
            return current;
        };
        
        dfs(root);
        int ans = 0;
        
        for(auto i : f){
            ans += i.second > 1;
        }
            
        return ans;
    }
};