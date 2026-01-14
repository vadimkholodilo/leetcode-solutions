namespace Solutions.Findfirstandlastpositionofelementinsortedarray;

public class Solution
{
    public int[] SearchRange(int[] nums, int target)
    {
        int firstIndex = FindBoundery(nums, target, true);
        if (firstIndex == -1)
            return [-1, -1];

        int lastIndex = FindBoundery(nums, target, false);

        return [firstIndex, lastIndex];
    }

    private static int FindBoundery(int[] nums, int target, bool first)
    {
        int result = -1;
        int l = 0;
        int r = nums.Length - 1;

        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (nums[m] == target)
            {
                result = m;
                if (first)
                    r = m - 1;
                else
                    l = m + 1;
            }
            else if (nums[m] < target)
                l = m + 1;
            else
                r = m - 1;
        }

        return result;
    }
}
