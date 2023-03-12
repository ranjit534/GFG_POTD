class Solution
{ // Question - Binary matrix having maximum number of 1s
public:
    vector<int> findMaxRow(vector<vector<int>> mat, int N)
    {
        vector<int> ans(2, 0);
        int i = 0, j = N - 1, c = 0;
        while (i < N && j >= 0)
        {
            if (mat[i][j] == 1)
            {
                j--;
                c++;
                ans[0] = i;
                ans[1] = c;
            }
            else
            {
                i++;
            }
        }
        return ans;
    }
};