namespace Solutions.Longestconsecutivesequence;

public class Solution
{
    public int LongestConsecutive(int[] nums)
    {
        if (nums is null || nums.Length == 0)
            return 0;

        int maxLength = 0;
        var numsSet = new HashSet<int>(nums);

        foreach (int num in numsSet)
        {
            if (numsSet.Contains(num - 1))
                continue;

            int currentNum = num;
            int currentLength = 1;
            while (numsSet.Contains(currentNum + 1))
            {
                currentNum++;
                currentLength++;
            }

            maxLength = Math.Max(currentLength, maxLength);
        }

        return maxLength;
    }
}
