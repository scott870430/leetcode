/*
 * @lc app=leetcode id=880 lang=cpp
 *
 * [880] Decoded String at Index
 * Explanation
We decode the string and N keeps the length of decoded string, until N >= K.
Then we go back from the decoding position.
If it's S[i] = d is a digit, then N = N / d before repeat and K = K % N is what we want.
If it's S[i] = c is a character, we return c if K == 0 or K == N
 */

// @lc code=start
class Solution
{
public:
    string decodeAtIndex(string S, int K)
    {
        long N = 0, i;
        for (i = 0; N < K; ++i)
            N = isdigit(S[i]) ? N * (S[i] - '0') : N + 1;
        while (i--)
            if (isdigit(S[i]))
                N /= S[i] - '0', K %= N;
            else if (K % N-- == 0)
                return string(1, S[i]);
        return "1234";
    }
};
// @lc code=end
