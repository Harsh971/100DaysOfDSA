struct impdata{
    int min, max, sum;
};

class Solution {
public:
    int minSubtreeSumBST(int target, Node *root) {
        const int inf = 1e9;
        
        queue<Node*> q;
        map<Node*, pair<int,int>> minmax;
        
        function<impdata(Node*, int)> traverse = [&](Node * current, int depth) -> impdata {
            if(current == nullptr){
                impdata newdata;
                newdata.min = inf;
                newdata.max = -inf;
                newdata.sum = 0;
                
                return newdata;
            }
            
            
            impdata left = traverse(current -> left, depth + 1);
            impdata right = traverse(current -> right, depth + 1);
            
            int currentSum = left.sum + right.sum + current -> data;
            if(currentSum == target)
                q.push(current);
                
            impdata newdata;
            newdata.sum = currentSum;
            newdata.min = min({current -> data, left.min, right.min});
            newdata.max = max({current -> data, left.max, right.max});
            
            minmax[current] = {left.max, right.min};
            
            return newdata;
        };
        
        traverse(root, 0);
        int size = 0;
        
        function<bool(Node*)> checkBST = [&](Node * current) -> bool {
            if(current == nullptr)
                return 1;
            
            ++size;
            
            if(minmax[current].first >= current -> data)
                return 0;
                
            if(minmax[current].second <= current -> data)
                return 0;
                
            return checkBST(current -> left) and checkBST(current -> right);
        };
        
        int ans = inf;
        while(q.size()){
            if(checkBST(q.front()))
                ans = min(ans, size);
                
            size = 0;
            q.pop();
        }
        
        return (ans == inf) ? -1 : ans;
    }
};