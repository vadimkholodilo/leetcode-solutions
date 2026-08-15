namespace Solutions.ValidAnagram;

public class Solution
{
    public bool IsAnagram(string s, string t)
    {
        if (s.Length != t.Length)
        {
            return false;
        }

        var sFreeqTable = CountFreequency(s);
        var tFreeqTable = CountFreequency(t);
        foreach ((var symble, var count) in tFreeqTable)
        {
            if (!sFreeqTable.TryGetValue(symble, out var sCount))
            {
                return false;
            }
            if (count != sCount)
            {
                return false;
            }
        }
        return true;
    }

    private Dictionary<char, int> CountFreequency(string s)
    {
        var result = new Dictionary<char, int>();
        foreach (var c in s)
        {
            if (result.ContainsKey(c))
            {
                result[c] += 1;
            }
            else
            {
                result.Add(c, 1);
            }
        }
        return result;
    }
}
