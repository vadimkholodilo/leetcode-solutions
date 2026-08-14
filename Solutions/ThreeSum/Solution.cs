namespace Solutions.ThreeSum;

public class Solution
{
    public IList<IList<int>> ThreeSum(int[] nums)
    {
        var result = new List<IList<int>>();
        nums.Sort();
        for (int i = 0; i < nums.Length; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int l = i + 1;
            int r = nums.Length - 1;
            while (l < r)
            {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum > 0)
                {
                    r--;
                }
                else if (sum < 0)
                {
                    l++;
                }
                else
                {
                    result.Add([nums[i], nums[l], nums[r]]);
                    l++;
                    r--;
                    while (l > 0 && nums[l] == nums[l - 1] && l < r)
                    {
                        l++;
                    }
                    while (r > l && r < nums.Length - 1 && nums[r] == nums[r + 1])
                    {
                        r--;
                    }
                }
            }
        }
        return result;
    }
}
