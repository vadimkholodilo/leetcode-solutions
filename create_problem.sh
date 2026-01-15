#!/bin/bash

# Function to convert string to PascalCase (for C# class names and namespaces)
to_pascal_case() {
    local input="$1"

    # Check if the input is already in PascalCase (starts with uppercase followed by mixed case)
    if [[ "$input" =~ ^[A-Z][a-zA-Z0-9]*$ ]]; then
        echo "$input"
        return
    fi

    # Replace hyphens and underscores with spaces, then convert to title case
    echo "$input" | sed -E 's/[_-]/ /g' | awk '{
        for(i=1; i<=NF; i++) {
            $i = toupper(substr($i,1,1)) tolower(substr($i,2))
        }
        $0 = $0 " "
        gsub(/ /, "")
    }1'
}

# Check if argument is provided
if [ $# -eq 0 ]; then
    echo "Error: Problem name not provided"
    echo "Usage: $0 <problem_name>"
    exit 1
fi

# Get the problem name from the first argument
PROBLEM_NAME="$1"

# Convert problem name to PascalCase
FORMATTED_NAME=$(to_pascal_case "$PROBLEM_NAME")

# Get the directory where the script is located
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# Define the paths to the Solutions and Tests directories
SOLUTIONS_DIR="$SCRIPT_DIR/Solutions/$FORMATTED_NAME"
TESTS_DIR="$SCRIPT_DIR/Tests"

# Create the directory for the problem
mkdir -p "$SOLUTIONS_DIR"

# Create the Solution.cs file with the correct namespace (file-scoped)
cat > "$SOLUTIONS_DIR/Solution.cs" << EOF
namespace Solutions.$FORMATTED_NAME;

public class Solution
{
    // TODO: Implement your solution here
}
EOF

# Create the corresponding test file in the Tests directory
TEST_FILE_PATH="$TESTS_DIR/${FORMATTED_NAME}Tests.cs"
cat > "$TEST_FILE_PATH" << EOF
using Xunit;
using Solutions.$FORMATTED_NAME;

namespace Tests;

public class ${FORMATTED_NAME}Tests
{
    [Fact]
    public void TestSolution()
    {
        var solution = new Solution();
        Assert.True(true);
    }
}
EOF

echo "Created problem directory and Solution class for: $FORMATTED_NAME"
echo "Directory: $SOLUTIONS_DIR"
echo "File: $SOLUTIONS_DIR/Solution.cs"
echo "Test File: $TEST_FILE_PATH"