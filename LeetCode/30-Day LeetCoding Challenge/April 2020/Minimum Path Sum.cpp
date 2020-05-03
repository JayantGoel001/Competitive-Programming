class Solution {
public:
    int minPathSum(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        for(int i=1;i<m;i++)
            a[0][i] += a[0][i-1];
        
        for(int i=1;i<n;i++)
            a[i][0] += a[i-1][0];
        
        for(int i=1;i<n;i++)
            for(int j=1;j<m;j++)
            {
                int mini = min(a[i-1][j] , a[i][j-1]);
                a[i][j] += mini;
            }
        
        return a[n-1][m-1];
    }
};
