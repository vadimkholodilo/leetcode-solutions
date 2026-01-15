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

# Function to convert PascalCase to kebab-case (for branch names)
to_kebab_case() {
    local input="$1"

    # If the input is in PascalCase, convert to kebab-case
    if [[ "$input" =~ ^[A-Z][a-zA-Z0-9]*$ ]]; then
        # Insert hyphens before capital letters (except the first one) and convert to lowercase
        echo "$input" | sed -E 's/(.)([A-Z])/\1-\2/g' | tr '[:upper:]' '[:lower:]'
    else
        # If it's already in kebab-case or snake_case, normalize it
        echo "$input" | sed 's/_/-/g' | tr '[:upper:]' '[:lower:]'
    fi
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

# Get the branch name in kebab-case format
BRANCH_NAME=$(to_kebab_case "$PROBLEM_NAME")

# Check if branch already exists
if git show-ref --verify --quiet "refs/heads/$BRANCH_NAME"; then
    echo "Branch $BRANCH_NAME already exists, switching to it"
    git checkout "$BRANCH_NAME" || {
        echo "Error: Could not switch to branch $BRANCH_NAME"
        exit 1
    }
else
    echo "Creating new branch: $BRANCH_NAME"
    git checkout -b "$BRANCH_NAME" || {
        echo "Error: Could not create branch $BRANCH_NAME"
        exit 1
    }
fi

echo "Created problem directory and Solution class for: $FORMATTED_NAME"
echo "Directory: $SOLUTIONS_DIR"
echo "File: $SOLUTIONS_DIR/Solution.cs"
echo "Test File: $TEST_FILE_PATH"
echo "Branch created: $BRANCH_NAME"