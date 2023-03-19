class Solution {
  public:
    vector<int> getDistinctDifference(int N, vector<int> &A) {
        // code here
        unordered_set<int>st;
        vector<int>left(N,0);
        vector<int>right(N,0);
        for(int i=0; i<N; i++)
        {
            left[i] = st.size();
            st.insert(A[i]);
        }
        st.clear();
        
        for(int i=N-1; i>=0; i--)
        {
            right[i] = st.size();
            st.insert(A[i]);
        }
        vector<int>ans;
        
        for(int i=0; i<N; i++)
        {
            ans.push_back(left[i]-right[i]);
        }
        return ans;
    }
};