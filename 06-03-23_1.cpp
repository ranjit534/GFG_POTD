class Solution // Question-Geek hates too many 1s
{
public:
    int noConseBits(int n)
    {
        for (int i = 31; i >= 2; i--)
        {
            int one = (1 << (i));                                     // largest bit
            int two = (1 << (i - 1));                                 // 2nd largest bit
            int three = (1 << (i - 2));                               // 3rd largest bit
            if ((n & one) != 0 && (n & two) != 0 && (n & three) != 0) // If all 3 consecutive bits are one then make the 3rd largest bit 0 to get maximum value of n
                n = n ^ (three);
        }
        return n;
    }
};