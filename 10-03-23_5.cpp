class Solution
{ // Question - Maximum Triplet product
public:
    long long maxTripletProduct(long long arr[], int n)
    {
        long long m1 = INT_MIN, m2 = INT_MIN, m3 = INT_MIN; // For storing 3 maximum element in the array.
        long long mi1 = INT_MAX, mi2 = INT_MAX;             // For storing 2 minimum element in the array.
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > m1)
            {
                m3 = m2;
                m2 = m1;
                m1 = arr[i];
            }
            else if (arr[i] > m2)
            {
                m3 = m2;
                m2 = arr[i];
            }
            else if (arr[i] > m3)
            {
                m3 = arr[i];
            }
            if (arr[i] < mi1)
            {
                mi2 = mi1;
                mi1 = arr[i];
            }
            else if (arr[i] < mi2)
            {
                mi2 = arr[i];
            }
        }
        return max(m1 * m2 * m3, mi1 * mi2 * m1);
    }
};