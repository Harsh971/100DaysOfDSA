class Solution {
  public:
    int maxIntersections(vector<vector<int>> lines, int N) {
        map<int,int> start, end;
        
        for(auto item : lines){
            start[item[0]]++;
            end[item[1]]++;
        }
        
        int startSum, endSum, ans;
        startSum = endSum = ans = 0;
        
        for(auto &e : end){
            e.second += endSum;
            endSum = e.second;
        }
        
        for(auto &e : start){
            e.second += startSum;
            startSum = e.second;
            
            int remove = 0;
            auto ptr = end.lower_bound(e.first);
            if(ptr != end.begin())
                --ptr, remove = (*ptr).second;
                
            ans = max(ans, e.second - remove);
        }
        
        return ans;
    }
};