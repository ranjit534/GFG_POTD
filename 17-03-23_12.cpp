long long int no_of_subarrays(int n, vector<int> &arr)
{ // Question - Number of Subarrays of 0's
    long long ans = 0, temp = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            temp++;
        }
        else
        {
            ans += temp * (temp + 1) / 2;
            temp = 0;
        }
    }
    return ans += temp * (temp + 1) / 2;
}