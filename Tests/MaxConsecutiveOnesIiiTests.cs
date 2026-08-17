using Xunit;
using Solutions.MaxConsecutiveOnesIii;

namespace Tests;

public class MaxConsecutiveOnesIiiTests
{
    [Theory]
    [InlineData(new[] { 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0 }, 2, 6)]
    [InlineData(new[] { 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1 }, 3, 10)]
    [InlineData(new[] { 0 }, 0, 0)]
    [InlineData(new[] { 1 }, 0, 1)]
    [InlineData(new[] { 0, 0, 0 }, 3, 3)]
    [InlineData(new[] { 1, 1, 1 }, 0, 3)]
    public void TestSolution(int[] nums, int k, int expected)
    {
        var solution = new Solution();
        Assert.Equal(expected, solution.LongestOnes(nums, k));
    }
}
