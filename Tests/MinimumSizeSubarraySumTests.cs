using Xunit;
using Solutions.Minimumsizesubarraysum;

namespace Tests;

public class MinimumSizeSubarraySumTests
{
    [Theory]
    [InlineData(new [] {2,3,1,2,4,3}, 7, 2)]
    [InlineData(new [] {1,4,4}, 4, 1)]
    [InlineData(new [] {1,1,1,1,1,1,1,1}, 11, 0)]
    public void TestSolution(int[] nums, int target, int expectedLength)
    {
        var solution = new Solution();
        Assert.Equal(expectedLength, solution.MinSubarrayLen(target, nums));
    }
}
