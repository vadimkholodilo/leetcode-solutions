using Xunit;
using Solutions.MaximumSubarray;

namespace Tests;

public class MaximumSubarrayTests
{
    [Theory]
    [InlineData(new[] { -2, 1, -3, 4, -1, 2, 1, -5, 4 }, 6)]
    [InlineData(new[] { 1 }, 1)]
    [InlineData(new[] { 5, 4, -1, 7, 8 }, 23)]
    [InlineData(new[] { -1 }, -1)]
    [InlineData(new[] { -3, -2, -1 }, -1)]
    [InlineData(new[] { 1, 2, 3, 4 }, 10)]
    public void TestSolution(int[] nums, int expected)
    {
        var solution = new Solution();
        Assert.Equal(expected, solution.MaxSubArray(nums));
    }
}
