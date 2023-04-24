class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int> arr)
    {
        int n = arr.size();
        
        stack<pair<int,int>> s;
        vector<pair<int,int>> inter(n, make_pair(-1, -1));
        
        for(int i = 0; i < n; i++){
            while(s.size() and s.top().first >= arr[i])
                s.pop();
                
            if(s.size()){
                pair<int,int> candidate = s.top();
                inter[i] = candidate;
            }
            
            s.push({arr[i], i});
        }
        
        while(s.size())
            s.pop();
            
        for(int i = n - 1; i > -1; i--){
            while(s.size() and s.top().first >= arr[i])
                s.pop();
            
            if(s.size()){
                pair<int,int> candidate = s.top();
                
                if(inter[i] == make_pair(-1, -1)){
                    inter[i] = candidate;
                }
                else{
                    int x = abs(i - inter[i].second);
                    int y = abs(i - candidate.second);
                    
                    bool change = 0;
                    
                    if(y < x){
                        change = 1;
                    }
                    else if(x == y){
                        if(candidate.first < inter[i].first){
                            change = 1;
                        }
                        else if(candidate.first == inter[i].first){
                            if(candidate.second < inter[i].second){
                                change = 1;
                            }
                        }
                    }
                    
                    if(change)
                        inter[i] = candidate;
                }
            }
            
            s.push({arr[i], i});
        }
        
        vector<int> ans(n);
        
        for(int i = 0; i < n; i++)
            ans[i] = inter[i].second;
            
        return ans;
    }
};
