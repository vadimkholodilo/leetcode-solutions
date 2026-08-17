namespace Solutions.MaximumAverageSubarrayI;

public class Solution
{
    public double FindMaxAverage(int[] nums, int k)
    {
        double maxAvg = -int.MaxValue;
        int sum = 0;
        for (int i = 0; i < k; i++)
        {
            sum += nums[i];
        }
        maxAvg = sum / (double)k;
        for (int i = k; i < nums.Length; i++)
        {
            sum += nums[i] - nums[i - k];
            maxAvg = Math.Max(maxAvg, sum / (double)k);
        }
        return maxAvg;
    }
}
