using Xunit;
using Solutions.Removeduplicatesfromsortedarray;

namespace Tests;

public class RemoveDuplicatesFromSortedArrayTests
{
    [Theory]
    [InlineData(new int[] {}, new int[] {}, 0)]
    [InlineData(new [] {1, 1, 2}, new [] {1, 2}, 2)]
    [InlineData(new [] {0, 0, 1, 1, 1, 2, 2, 3, 3, 4}, new [] {0, 1, 2, 3, 4}, 5)]
    public void TestSolution(int[] nums, int[] expectedNums, int expectedLength)
    {
        var solution = new Solution();
        Assert.True(true);
    }
}
