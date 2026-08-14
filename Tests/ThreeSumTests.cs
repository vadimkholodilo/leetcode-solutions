using System.Linq;
using Xunit;
using Solutions.ThreeSum;

namespace Tests;

public class ThreeSumTests
{
    [Theory]
    [InlineData(new[] { -1, 0, 1, 2, -1, -4 }, new[] { "-1,-1,2", "-1,0,1" })]
    [InlineData(new[] { 0, 1, 1 }, new string[] { })]
    [InlineData(new[] { 0, 0, 0 }, new[] { "0,0,0" })]
    [InlineData(new[] { 0, 0, 0, 0 }, new[] { "0,0,0" })]
    [InlineData(new[] { -2, 0, 1, 1, 2 }, new[] { "-2,0,2", "-2,1,1" })]
    [InlineData(new[] { 1, 2, -2, -1 }, new string[] { })]
    public void TestSolution(int[] nums, string[] expectedTriplets)
    {
        var solution = new Solution();
        var result = solution.ThreeSum(nums);

        var actual = result
            .Select(t => string.Join(",", t.OrderBy(x => x)))
            .OrderBy(s => s)
            .ToArray();
        var expected = expectedTriplets.OrderBy(s => s).ToArray();

        Assert.Equal(expected, actual);
    }
}
