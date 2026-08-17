namespace Solutions.MaxConsecutiveOnesIii;

public class Solution
{
    public int LongestOnes(int[] nums, int k)
    {
        int maxLength = 0;
        int flippedZerosCount = 0;
        int l = 0;

        for (int r = 0; r < nums.Length; r++)
        {
            if (nums[r] == 0)
                flippedZerosCount++;

            while (flippedZerosCount > k)
            {
                if (nums[l] == 0)
                    flippedZerosCount--;

                l++;
            }
            maxLength = Math.Max(maxLength, r - l + 1);
        }

        return maxLength;
    }
}
