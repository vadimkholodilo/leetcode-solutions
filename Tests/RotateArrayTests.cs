using Xunit;
using Solutions.Rotatearray;

namespace Tests;

public class RotateArrayTests
{
    [Theory]
    [InlineData(new int[] {}, 1, new int[] {})]
    [InlineData(new [] {1, 2, 3, 4, 5, 6, 7}, 3, new [] {5, 6, 7, 1, 2, 3, 4})]
    [InlineData(new [] {-1,-100,3,99}, 2, new [] {3,99,-1,-100})]
    [InlineData(new [] {1, 2, 3, 4, 5, 6, 7}, 7, new [] {1, 2, 3, 4, 5, 6, 7})]
    public void TestSolution(int[] nums, int k, int[] modifiedNums)
    {
        var solution = new Solution();

        solution.Rotate(nums, k);

        Assert.Equal(modifiedNums, nums);
    }
}
