class Solution{
public:
    bool makePalindrome(int n,vector<string> &arr){
        map<string, int> need;
        
        for(auto current : arr){
            if(need.find(current) != need.end()){
                if(need[current]){
                    --need[current];
                    continue;
                }
            }
                
            string rev = current;
            reverse(rev.begin(), rev.end());
            ++need[rev];
        }
        
        bool ok = 1;
        for(auto i : need){
            if(i.second > 0){
                if(ok){
                    string current = i.first;
                    string rev = current;
                    
                    reverse(rev.begin(), rev.end());
                    
                    if(rev != current)
                        return 0;
                        
                    ok = 0;
                }
                else
                    return 0;
            }
        }
        
        return 1;
    }
};