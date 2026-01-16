using Xunit;
using Solutions.MoveZeroes;

namespace Tests;

public class MoveZeroesTests
{
    [Theory]
    [InlineData(new int[] { }, new int[] { })]
    [InlineData(new [] { 0 }, new [] { 0 })]
    [InlineData(new [] { 0, 1, 2, 0, 3, 4 }, new [] { 1, 2, 3, 4, 0, 0 })]
    public void TestSolution(int[] nums, int[] expectedNums)
    {
        var solution = new Solution();
        solution.MoveZeroes(nums);
        Assert.Equal(expectedNums, nums);
    }
}
