namespace Solutions.ProductOfArrayExceptSelf;

public class Solution
{
    public int[] ProductExceptSelf(int[] nums)
    {
        var prefixes = new int[nums.Length];
        var postfixes = new int[nums.Length];
        var defaultValue = 1;
        for (int i = 0; i < nums.Length; i++)
        {
            if (i == 0)
                prefixes[0] = defaultValue;
            else
                prefixes[i] = prefixes[i - 1] * nums[i - 1];
        }
        for (int i = nums.Length - 1; i >= 0; i--)
        {
            if (i == nums.Length - 1)
                postfixes[i] = defaultValue;
            else
                postfixes[i] = postfixes[i + 1] * nums[i + 1];
        }
        var answers = new int[nums.Length];
        for (int i = 0; i < nums.Length; i++)
        {
            answers[i] = prefixes[i] * postfixes[i];
        }
        return answers;
    }
}
