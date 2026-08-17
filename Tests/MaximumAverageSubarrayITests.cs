using Xunit;
using Solutions.MaximumAverageSubarrayI;

namespace Tests;

public class MaximumAverageSubarrayITests
{
    [Theory]
    [InlineData(new[] { 1, 12, -5, -6, 50, 3 }, 4, 12.75)]
    [InlineData(new[] { 5 }, 1, 5.0)]
    [InlineData(new[] { -1, -2, -3 }, 3, -2.0)]
    [InlineData(new[] { 0, 4, 0, 3, 2 }, 1, 4.0)]
    [InlineData(new[] { 1, 1, 1, 1, 1 }, 5, 1.0)]
    public void TestSolution(int[] nums, int k, double expected)
    {
        var solution = new Solution();
        Assert.Equal(expected, solution.FindMaxAverage(nums, k), precision: 5);
    }
}
