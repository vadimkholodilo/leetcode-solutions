namespace Solutions.Majorityelement;

public class Solution
{
    public int MajorityElement(int[] nums)
    {
        if (nums.Length == 1)
            return nums[0];

        int k = nums.Length / 2;
        var freeqTable = new Dictionary<int, int>();

        foreach (var num in nums)
        {
            if (freeqTable.ContainsKey(num))
                freeqTable[num] += 1;
            else
                freeqTable[num] = 1;
        }

        foreach ((var key, var value) in freeqTable)
        {
            if (value > k)
                return key;
        }

        return -1;
    }

    public int MajorityElementWithoutHashTable(int[] nums)
    {
        int candidate = 0;
        int count = 0;

        foreach (var num in nums)
        {
            if (count == 0)
                candidate = num;

            if (candidate == num)
                count++;
            else
                count--;
        }

        return candidate;
    }
}
