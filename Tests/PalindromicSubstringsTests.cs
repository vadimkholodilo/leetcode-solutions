using Xunit;
using Solutions.PalindromicSubstrings;

namespace Tests;

public class PalindromicSubstringsTests
{
    [Theory]
    [InlineData("abc", 3)]
    [InlineData("aaa", 6)]
    public void TestSolution(string s, int expectedCount)
    {
        var solution = new Solution();
        Assert.Equal(expectedCount, solution.CountSubstrings(s));
    }
}
