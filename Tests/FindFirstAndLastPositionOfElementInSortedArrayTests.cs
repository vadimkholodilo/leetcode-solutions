using Xunit;
using Solutions.Findfirstandlastpositionofelementinsortedarray;

namespace Tests;

public class FindFirstAndLastPositionOfElementInSortedArrayTests
{
    [Theory]
    [InlineData(new int[] {}, 0, new [] {-1, -1})]
    [InlineData(new [] {5, 7, 7, 8, 8, 10}, 8, new [] {3, 4})]
    [InlineData(new [] {5, 7, 7, 8, 8, 10}, 6, new [] {-1, -1})]
    public void TestSolution(int[] nums, int target, int[] expectedRange)
    {
        var solution = new Solution();
        Assert.Equal(expectedRange, solution.SearchRange(nums, target));
    }
}
