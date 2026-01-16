namespace Solutions.MoveZeroes;

public class Solution
{
    public void MoveZeroes(int[] nums)
    {
        int l = 0;
        for (int r = 0; r < nums.Length; r++)
        {
            if (nums[r] == 0)
                continue;

            Swap(nums, l, r);
            l++;
        }
    }

    private static void Swap(int[] nums, int firstIndex, int secondIndex)
    {
        int temp = nums[firstIndex];
        nums[firstIndex] = nums[secondIndex];
        nums[secondIndex] = temp;
    }
}
