using Xunit;
using Solutions.TwoSum;

namespace Tests;

public class TwoSumTests
{
    [Theory]
    [InlineData(new[] { 2, 7, 11, 15 }, 9, new[] { 0, 1 })]
    [InlineData(new[] { 3, 2, 4 }, 6, new[] { 1, 2 })]
    [InlineData(new[] { 3, 3 }, 6, new[] { 0, 1 })]
    [InlineData(new[] { 0, 4, 3, 0 }, 0, new[] { 0, 3 })]
    [InlineData(new[] { -3, 4, 3, 90 }, 0, new[] { 0, 2 })]
    public void TestSolution(int[] nums, int target, int[] expected)
    {
        var solution = new Solution();
        Assert.Equal(expected, solution.TwoSum(nums, target));
    }
}
