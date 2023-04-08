class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        stack<int> st;
        
        for(auto i : arr){
            if(st.size() == 0)
                st.push(i);
            else if(st.top() < 0 ^ i < 0)
                st.pop();
            else
                st.push(i);
        }
        
        vector<int> ans;
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};