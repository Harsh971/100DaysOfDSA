class Solution{

    public:
    int ladoos(Node* root, int home, int k)
    {
        const int inf = 1e9;
        
        map<Node *, int> distance;
        map<Node *, vector<Node *>> graph;
        
        Node * source;
        
        function<void(Node *, Node *)> traverse = [&](Node * current, Node * parent) {
            if(current == nullptr)
                return;
                
            if(parent != nullptr)
                graph[current].push_back(parent);
            if(current -> left != nullptr)
                graph[current].push_back(current -> left);
            if(current -> right != nullptr)
                graph[current].push_back(current -> right);
                
            if(current -> data == home){
                distance[current] = 0;
                source = current;
            }
            else{
                distance[current] = inf;
            }
            
            traverse(current -> left, current);
            traverse(current -> right, current);
        };
        
        traverse(root, nullptr);
        
        queue<Node *> q;
        q.push(source);
        int ans = 0;
        
        while(!q.empty()){
            Node * current = q.front();
            q.pop();
            
            ans += current -> data;
            
            if(distance[current] < k){
                for(auto child : graph[current]){
                    if(distance[child] > distance[current] + 1){
                        distance[child] = distance[current] + 1;
                        q.push(child);
                    }
                }
            }
        }
        
        return ans;
    }


};