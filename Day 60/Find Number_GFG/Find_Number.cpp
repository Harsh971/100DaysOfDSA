class Solution{
public:
    long long findNumber(long long n){
        vector<int> v = {9, 1, 3, 5, 7};
        
        function<string(long long)> base5 = [&](long long x) -> string {
        	if(x == 0)
        		return "";
    
        	string ans = base5(x / 5 - ((x % 5 == 0) ? 1 : 0)) + to_string(v[x % 5]);
        	return ans;
        };
        
        return stol(base5(n));
    }
};