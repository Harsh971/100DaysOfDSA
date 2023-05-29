class Solution {
  public:
    vector<string> CamelCase(int N, vector<string> Dictionary, string pattern) {
        vector<string> ans;
        for(auto current : Dictionary){
            
            string need = "";
            for(auto i : current)
                if(isupper(i))
                    need += i;
                    
            bool ok = 1;
            if(need.size() < pattern.size())
                continue;
                
            for(int i = 0; i < pattern.size(); i++){
                if(need[i] != pattern[i]){
                    ok = 0;
                    break;
                }
            }
            
            if(ok)
                ans.push_back(current);
        }
        
        if(ans.size() == 0)
            ans.push_back("-1");
            
        return ans;
    }
};