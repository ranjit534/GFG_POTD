class Solution
{ // Question - Yet another query problem
public:
    vector<int> solveQueries(int N, int num, vector<int> &A, vector<vector<int>> &Q)
    {
        unordered_map<int, int> m;
        vector<int> act(N, 0);
        for (auto t : A)
        {
            m[t]++;
        }
        for (int i = 0; i < N; i++)
        {
            act[i] = m[A[i]]--;
        }
        vector<int> an;
        for (int i = 0; i < num; i++)
        {
            int l = Q[i][0], r = Q[i][1], k = Q[i][2], ans = 0;
            for (int j = l; j <= r; j++)
            {
                if (act[j] == k)
                    ans++;
            }
            an.push_back(ans);
        }
        return an;
    }
};
