class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        vector<pair<int,int>> input(n + 1);
        vector<long long> pre(n + 1);
        
        pre[0] = 0;
        input[0] = {-10, -10};
        
        for(int i = 1; i < n + 1; i++){
            input[i].first = arr[i - 1];
            input[i].second = i - 1;
        }
        
        sort(input.begin(), input.end());
        
        for(int i = 1; i < n + 1; i++){
            pre[i] = pre[i - 1] + input[i].first;
        }
        
        vector<long long> ans(n);
        
        for(int i = 1; i < n + 1; i++){
            auto pos = lower_bound(input.begin(), input.end(), make_pair(input[i].first, -1)) - input.begin();
            --pos;
            
            ans[input[i].second] = pre[pos];
        }
        
        return ans;
    }
};