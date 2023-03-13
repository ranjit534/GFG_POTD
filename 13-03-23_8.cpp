class Solution // Question - Maximum Possible Value
{
public:
    long long maxPossibleValue(int N, vector<int> A, vector<int> B)
    {
        long long ans = 0;
        long long prev = 0;
        long long mini = INT_MAX;
        for (int i = 0; i < N; i++)
        {
            long long side = A[i];
            long long fre = B[i] / 4;
            ans += (4 * side * fre); // For square
            if (B[i] != 1)
                mini = min(side, mini); // To store minimum side having quantity left between 1<Quantity<4.
            if (B[i] % 4 == 2 || B[i] % 4 == 3)
            {
                if (prev == 0)
                {
                    prev = side;
                }
                else
                {
                    ans += (2 * prev) + (2 * side); // For rectangle
                    prev = 0;
                }
            }
        }
        if (prev != 0)
        {
            ans = max(ans, ans - 2 * mini + 2 * prev); // Subtracting minimum side and adding previous one to get maximum possible value
        }
        return ans;
    }
};