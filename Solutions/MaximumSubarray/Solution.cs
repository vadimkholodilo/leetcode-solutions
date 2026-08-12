namespace Solutions.MaximumSubarray;

public class Solution
{
    public int MaxSubArray(int[] nums)
    {
        int result = nums[0];
        int maxEnding = nums[0];

        for (int i = 1; i < nums.Length; i++)
        {
            maxEnding = Math.Max(nums[i], maxEnding + nums[i]);
            result = Math.Max(result, maxEnding);
        }

        return result;
    }
}
