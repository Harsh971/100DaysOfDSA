vector<int> z_function_trivial(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1; i < n; ++i)
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
    return z;
}

class Solution{   
public:
    int addMinChar(string str){    
        string x, y;
        x = str;
        y = str;
        reverse(y.begin(), y.end());
        
        string t = x + "?" + y;
        
        vector<int> z = z_function_trivial(t);
        
        for(int i = str.size() + 1; i < z.size(); i++){
            int need = z.size() - i;
            
            if(z[i] == need){
                return i - str.size() - 1;
            }
        }
    }
};