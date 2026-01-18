namespace Solutions.PalindromicSubstrings;

public class Solution
{
    public int CountSubstrings(string s)
    {
        int numSubstrings = 0;

        for (int i = 0; i < s.Length; i++)
        {
            numSubstrings += CountPalindromes(s, i, i);
            numSubstrings += CountPalindromes(s, i, i + 1);
        }

        return numSubstrings;
    }

    private static int CountPalindromes(string s, int l, int r)
    {
        int result = 0;

        while (l >= 0 && r < s.Length && s[l] == s[r])
        {
            result++;
            l--;
            r++;
        }

        return result;
    }
}
