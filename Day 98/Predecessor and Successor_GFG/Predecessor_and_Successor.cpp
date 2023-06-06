class Solution
{
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        pre = suc = nullptr;
        
        function<void(Node*)> dfs = [&](Node * current) {
            if(current -> key < key){
                if(pre == nullptr or pre -> key < current -> key)
                    pre = current;
            }
            
            if(current -> key > key){
                if(suc == nullptr or suc -> key > current -> key)
                    suc = current;
            }
            
            if(current -> left != nullptr and current -> right != nullptr){
                if(current -> left -> key < key and current -> right -> key < key)
                    dfs(current -> right);
                else if(current -> left -> key > key and current -> right -> key > key)
                    dfs(current -> left);
                else{
                    dfs(current -> left);
                    dfs(current -> right);
                }
                
            }
            else if(current -> left != nullptr)
                dfs(current -> left);
            else if(current -> right != nullptr)
                dfs(current -> right);
        };
        
        dfs(root);
    }
};