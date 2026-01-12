using Xunit;
using Solutions.Longestsubstringwithoutrepeatingcharacters;

namespace Tests;

public class LongestsubstringwithoutrepeatingcharactersTests
{
    [Theory]
    [InlineData("abcabcbb", 3)]
    [InlineData("bbbbb", 1)]
    [InlineData("pwwkew", 3)]
    public void TestSolution(string s, int expectedLength)
    {
        var solution = new Solution();
        Assert.Equal(expectedLength, solution.LengthOfLongestSubstring(s));
    }
}
