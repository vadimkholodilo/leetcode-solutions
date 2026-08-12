namespace Solutions.TwoSum;

public class Solution
{
    public int[] TwoSum(int[] nums, int target)
    {
        var result = new int[2];
        var map = new Dictionary<int, int>();

        for (var i = 0; i < nums.Length; i++)
        {
            var complement = target - nums[i];

            if (map.ContainsKey(complement))
            {
                result[0] = map[complement];
                result[1] = i;
                break;
            }

            map[nums[i]] = i;
        }

        return result;
    }
}
