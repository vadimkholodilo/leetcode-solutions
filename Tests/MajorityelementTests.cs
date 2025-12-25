using Xunit;
using Solutions.Majorityelement;

namespace Tests;

public class MajorityelementTests
{
    [Theory]
    [InlineData(new [] { 1 }, 1)]
    [InlineData(new [] { 3, 2, 3 }, 3)]
    [InlineData(new [] {2, 2, 1, 1, 1, 2, 2}, 2)]
    public void TestSolution(int[] nums, int majorityElement)
    {
        var solution = new Solution();
        Assert.Equal(majorityElement, solution.MajorityElement(nums));
        Assert.Equal(majorityElement, solution.MajorityElementWithoutHashTable(nums));
    }
}
