
int diagonalSum(vector<vector<int>>& mat) 
{
    int n=mat.size();
    int sum=0;
    int i=0,j=0;
    while(i<n)
    {
        sum+=mat[i][j];
        i++;
        j++;
    }
    i=0;
    j=n-1;
    while(i<n)
    {
        if(i!=j)   sum+=mat[i][j];
        i++;
        j--;
    }
    return sum;
}
int main() 
{
    vector<vector<int>> mat={
            {1,2,3},
            {4,5,6},
            {7,8,9}  
    };
   
    cout<<diagonalSum(mat)<<endl;
  return 0; 
}
