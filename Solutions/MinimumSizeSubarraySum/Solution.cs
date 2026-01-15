namespace Solutions.Minimumsizesubarraysum;

public class Solution
{
    public int MinSubarrayLen(int target, int[] nums)
    {
        int minLength = int.MaxValue;
        int totalSum = 0;
        int l = 0;

        for (int r = 0; r < nums.Length; r++)
        {
            totalSum += nums[r];
            while (totalSum >= target)
            {
                int currentLength = r - l + 1;
                minLength = Math.Min(minLength, currentLength);
                totalSum -= nums[l];
                l++;
            }
        }

        return minLength == int.MaxValue ? 0 : minLength;
    }
}