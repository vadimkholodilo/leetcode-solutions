using System.Runtime.CompilerServices;
using Xunit;
using Solutions.Stringcompression;

namespace Tests;

public class StringCompressionTests
{
    [Theory]
    [InlineData("aabbccc", 6, "a2b2c3")]
    [InlineData("a", 1, "a")]
    [InlineData("abbbbbbbbbbbb", 4, "ab12")]
    public void TestSolution(string input, int expectedLength, string expectedOutput)
    {
        var solution = new Solution();
        var inputArray = input.ToCharArray();

        var actualLength = solution.Compress(inputArray);

        Assert.Equal(expectedLength, actualLength);
        Assert.Equal(expectedOutput.ToCharArray(), inputArray[..expectedLength]);
    }
}
