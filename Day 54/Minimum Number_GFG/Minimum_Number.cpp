class Solution{
public:
    int minimumNumber(int n,vector<int> &arr){
        // Code here
        int mini=INT_MAX;
        for(auto it:arr){
            mini=min(mini,it);
        }
        for(auto it:arr){
            if(it%mini!=0) return 1;
        }
        return mini;
    }
};