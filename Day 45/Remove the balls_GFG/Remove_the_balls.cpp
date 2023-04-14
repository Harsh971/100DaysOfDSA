lass Solution {
  public:
    int finLength(int N, vector<int> color, vector<int> radius) {
        stack<pair<int,int>> current;
        int index = 0;
        
        while(index < N){
            while(index < N and current.size() and current.top() == make_pair(color[index], radius[index]))
                current.pop(), ++index;
            
            if(index < N){
                current.push({color[index], radius[index]});
                ++index;
            }
        }
        
        return current.size();
    }
};
