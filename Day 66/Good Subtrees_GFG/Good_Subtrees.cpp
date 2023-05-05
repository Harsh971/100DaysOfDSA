class Solution{
public:
    int goodSubtrees(Node *root,int k){
        int ans = 0;
        
        function<set<int>(Node *)> dfs = [&](Node * node) -> set<int> {
            set<int> current;
            
            if(node == nullptr)
                return current;
                
            current.insert(node -> data);
        
            set<int> left = dfs(node -> left);
            set<int> right = dfs(node -> right);
            
            for(auto i : left)
                current.insert(i);
            for(auto i : right)
                current.insert(i);
                
            ans += current.size() <= k;
            
            return current;
        };
        
        dfs(root);
        
        return ans;
    }
};
