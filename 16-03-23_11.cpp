class Solution
{ // Question - Second smallest number
public:
    string secondSmallest(int S, int D)
    {
        if (S > 9 * D || D == 1) // Can't be represented as D digit number
            return "-1";
        vector<int> v(D, 0);
        int sum = S - 1;
        while (D--)
        { // To find the smallest number
            if (sum <= 9)
            {
                v[D] = sum;
                break;
            }
            else
            {
                v[D] = 9;
                sum -= 9;
            }
        }
        v[0] += 1;
        int ind = v.size() - 1;
        for (int i = v.size() - 1; i >= 0; i--)
        {
            if (v[i] == 9)
            {
                ind = i;
            }
            else
                break;
        }
        if (ind == 0)
        {
            return "-1";
        }
        v[ind] -= 1; // To get the second smallest number
        v[ind - 1] += 1;
        string ans = "";
        for (auto t : v)
        {
            ans += to_string(t);
        }
        return ans;
    }
};