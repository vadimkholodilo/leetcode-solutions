namespace Solutions.SquaresOfASortedArray;

public class Solution
{
    public int[] SortedSquares(int[] nums)
    {
        var result = new int[nums.Length];
        int left = 0;
        int right = nums.Length - 1;
        int writeIdx = nums.Length - 1;
        while (left <= right)
        {
            int leftSq = nums[left] * nums[left];
            int rightSq = nums[right] * nums[right];
            if (leftSq > rightSq)
            {
                result[writeIdx] = leftSq;
                left++;
            }
            else
            {
                result[writeIdx] = rightSq;
                right--;
            }
            writeIdx--;
        }
        return result;
    }
}
