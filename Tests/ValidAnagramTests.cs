using Xunit;
using Solutions.ValidAnagram;

namespace Tests;

public class ValidAnagramTests
{
    [Theory]
    [InlineData("anagram", "nagaram", true)]
    [InlineData("rat", "car", false)]
    [InlineData("a", "a", true)]
    [InlineData("a", "ab", false)]
    [InlineData("ab", "a", false)]
    [InlineData("aacc", "ccac", false)]
    [InlineData("aabbcc", "abcabc", true)]
    public void TestSolution(string s, string t, bool expected)
    {
        var solution = new Solution();
        Assert.Equal(expected, solution.IsAnagram(s, t));
    }
}
