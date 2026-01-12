namespace Solutions.Longestsubstringwithoutrepeatingcharacters;

public class Solution
{
    public int LengthOfLongestSubstring(string s)
    {
        int maxLength = 0;
        var visitedChars = new HashSet<char>();
        int l = 0;

        for (int r = 0; r < s.Length; r++)
        {
            while (visitedChars.Contains(s[r]))
            {
                visitedChars.Remove(s[l]);
                l++;
            }
            visitedChars.Add(s[r]);
            int currentLength = r - l + 1;
            maxLength = Math.Max(maxLength, currentLength);
        }

        return maxLength;
    }
}
