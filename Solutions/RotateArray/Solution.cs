namespace Solutions.Rotatearray;

public class Solution
{
    public void Rotate(int[] nums, int k)
    {
        if (nums is null || nums.Length == 0)
            return;

        k %= nums.Length;

        if (k == 0)
            return;

        ReverseArray(nums, 0, nums.Length - 1);
        ReverseArray(nums, 0, k - 1);
        ReverseArray(nums, k, nums.Length - 1);
    }

    private void ReverseArray(int[] nums, int firstIndex, int lastIndex)
    {
        while (firstIndex < lastIndex)
        {
            int temp = nums[firstIndex];
            nums[firstIndex] = nums[lastIndex];
            nums[lastIndex] = temp;
            firstIndex++;
            lastIndex--;
        }
    }
}
