using Xunit;
using Solutions.SquaresOfASortedArray;

namespace Tests;

public class SquaresOfASortedArrayTests
{
    [Theory]
    [InlineData(new[] { -4, -1, 0, 3, 10 }, new[] { 0, 1, 9, 16, 100 })]
    [InlineData(new[] { -7, -3, 2, 3, 11 }, new[] { 4, 9, 9, 49, 121 })]
    [InlineData(new[] { -5 }, new[] { 25 })]
    [InlineData(new[] { 0 }, new[] { 0 })]
    [InlineData(new[] { -3, -2, -1 }, new[] { 1, 4, 9 })]
    [InlineData(new[] { 1, 2, 3 }, new[] { 1, 4, 9 })]
    public void TestSolution(int[] nums, int[] expected)
    {
        var solution = new Solution();
        Assert.Equal(expected, solution.SortedSquares(nums));
    }
}
