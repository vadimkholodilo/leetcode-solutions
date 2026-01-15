namespace Solutions.Besttimetobuyandsellstock;

public class Solution
{
    public int MaxProfit(int[] prices)
    {
        if (prices is null || prices.Length < 2)
            return 0;

        int maxProfit = 0;

        int l = 0;
        int r = 1;

        while (l < r && r < prices.Length)
        {
            if (prices[l] > prices[r])
                l = r;
            else
            {
                int currentProfit = prices[r] - prices[l];
                if (maxProfit < currentProfit)
                    maxProfit = currentProfit;
            }

                r++;
        }

        return maxProfit;
    }
}
