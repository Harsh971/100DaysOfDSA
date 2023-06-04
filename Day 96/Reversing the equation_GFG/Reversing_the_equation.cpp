class Solution
{
  public:
    string reverseEqn (string s)
        {
            vector<string> eq;
            
            string current = "";
            
            for(auto i : s){
                if(isdigit(i))
                    current += i;
                else{
                    if(current != "")
                        eq.push_back(current);
                    string t = "";
                    t += i;
                    eq.push_back(t);
                    current = "";
                }
            }
            
            if(current != "")
                eq.push_back(current);
                
            reverse(eq.begin(), eq.end());
            
            string ans = "";
            
            for(auto i : eq)
                for(auto j : i)
                    ans += j;
                    
            return ans;
        }
};