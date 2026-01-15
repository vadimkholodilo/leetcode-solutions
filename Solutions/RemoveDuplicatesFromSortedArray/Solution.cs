namespace Solutions.Removeduplicatesfromsortedarray;

public class Solution
{
    public int RemoveDuplicates(int[] nums)
    {
        if (nums is null || nums.Length == 0)
            return 0;

        int writeIndex = 1;

        for (int readIndex = 1; readIndex < nums.Length; readIndex++)
        {
            if (nums[readIndex] != nums[readIndex - 1])
            {
                nums[writeIndex] = nums[readIndex];
                writeIndex++;
            }
        }

        return writeIndex;
    }
}
