class Solution {
  public:
    vector<string> addOperators(string S, int target) {
        vector<string> ans;
    
        function<void(int, string, string, char, long long, long long)> helper = [&](int p, string current, string last, char lastOp, long long lastVal, long long res) {
            if(p == S.size()){
                if(last.size() == 0 and res == (long long)target)
                    ans.push_back(current);
                
                return;
            }
            
            last += S[p];
    
            if(last != "0")
                helper(p + 1, current, last, lastOp, lastVal, res); // 12 -> 123
                
            // what if last = 0  0...
    
            string x, y, z;
            x = y = z = current;
    
            if(x.size() == 0){
                helper(p + 1, last, "", '!', stol(last), stol(last));
            }
            else{
                x += "+" + last;
                y += "-" + last;
                z += "*" + last;
    
                helper(p + 1, x, "", '+', stol(last), res + stol(last));
                helper(p + 1, y, "", '-', stol(last), res - stol(last));
    
                if(lastOp == '-'){
                    res += lastVal;
                    lastVal *= stol(last);
                    res -= lastVal;
                    helper(p + 1, z, "", lastOp, lastVal, res);
                }
                else if(lastOp == '+'){
                    res -= lastVal;
                    lastVal *= stol(last);
                    res += lastVal;
                    helper(p + 1, z, "", lastOp, lastVal, res);
                }   
                else{
                    helper(p + 1, z, "", lastOp, stol(last), res * stol(last));
                }     
            }   
        };
        

        helper(0, "", "", '!', 0, 0);
        //     p, current, last, lastOp, lastVal, res
            
        return ans;
    }
};