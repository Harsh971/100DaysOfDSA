int ds[1020];

int find(int x){
    if(ds[x] < 0)
    {
        return x;
    }
    return ds[x] = find(ds[x]);
}
void merge(int a, int b)
{
    if(a==b)
    {
        return ;
    }
    if(ds[a] > ds[b])
    {
        swap(a,b);
    }
    ds[a] += ds[b];
    ds[b] = a;
}
class Solution {
  public:
    vector<string> avoidExplosion(vector<vector<int>> mix, int n, vector<vector<int>> danger, int m) {
                                      
    vector<string> ans;
    for(int i=0; i<n+1; i++)
    {
        ds[i] = -1;
    }
    for(int i=0; i<n; i++)
    {
        int a = find(mix[i][0]);
        int b = find(mix[i][1]);
        if(a>b)
        {
            swap(a,b);
        }
        bool ok = 1;
        
        for(int j=0; j<m; j++)
        {
            int x = find(danger[j][0]);
            int y = find(danger[j][1]);
            if(x>y){
                swap(x,y);
            }   
            if(a==x and b==y){
                ok = 0;
                break;
            }
        }
        if(ok)
        {
            merge(a,b);
            ans.push_back("Yes");
        }
        else
        {
            ans.push_back("No");
        }
    }
    return ans;
        
    }
};