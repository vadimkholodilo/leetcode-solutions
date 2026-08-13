using Xunit;
using Solutions.ProductOfArrayExceptSelf;

namespace Tests;

public class ProductOfArrayExceptSelfTests
{
    [Theory]
    [InlineData(new[] { 1, 2, 3, 4 }, new[] { 24, 12, 8, 6 })]
    [InlineData(new[] { -1, 1, 0, -3, 3 }, new[] { 0, 0, 9, 0, 0 })]
    [InlineData(new[] { 0, 4, 0 }, new[] { 0, 0, 0 })]
    [InlineData(new[] { -1, -2, -3 }, new[] { 6, 3, 2 })]
    [InlineData(new[] { 3, 5 }, new[] { 5, 3 })]
    public void TestSolution(int[] nums, int[] expected)
    {
        var solution = new Solution();
        Assert.Equal(expected, solution.ProductExceptSelf(nums));
    }
}
