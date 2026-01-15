using Xunit;
using Solutions.Besttimetobuyandsellstock;

namespace Tests;

public class BestTimeToBuyAndSellStockTests
{
    [Theory]
    [InlineData(new int[] {}, 0)]
    [InlineData(new [] {7,1,5,3,6,4}, 5)]
    [InlineData(new [] {7,6,4,3,1}, 0)]
    public void TestSolution(int[] prices, int expectedMaxProfit)
    {
        var solution = new Solution();
        Assert.Equal(expectedMaxProfit, solution.MaxProfit(prices));
    }
}
