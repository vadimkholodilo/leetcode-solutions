namespace Solutions.Stringcompression;

public class Solution
{
    public int Compress(char[] chars)
    {
        int readIndex = 0;
        int writeIndex = 0;
        while (readIndex < chars.Length)
        {
            char currentChar = chars[readIndex];
            int count = 0;
            while (readIndex < chars.Length && chars[readIndex] == currentChar)
            {
                count++;
                readIndex++;
            }

            chars[writeIndex] = currentChar;
            writeIndex++;

            if (count > 1)
            {
                foreach (var c in count.ToString())
                {
                    chars[writeIndex] = c;
                    writeIndex++;
                }
            }

        }

        return writeIndex;
    }
}