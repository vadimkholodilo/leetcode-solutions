using Xunit;
using Solutions.Longestconsecutivesequence;

namespace Tests;

public class LongestConsecutiveSequenceTests
{
    [Theory]
    [InlineData(new int[] {}, 0)]
    [InlineData(new[] {1}, 1)]
    [InlineData(new [] {100,4,200,1,3,2}, 4)]
    [InlineData(new [] {0,3,7,2,5,8,4,6,0,1}, 9)]
    [InlineData(new [] {1,0,1,2}, 3)]
    public void TestSolution(int[] nums, int expectedLength)
    {
        var solution = new Solution();
        Assert.Equal(expectedLength, solution.LongestConsecutive(nums));
    }
}
