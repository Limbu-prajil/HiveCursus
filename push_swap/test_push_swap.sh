#!/bin/bash

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Path to the push_swap and checker programs
PUSH_SWAP="./push_swap"
CHECKER="./checker_Mac" # Change to checker_linux if on Linux

# Check if push_swap and checker exist
if [ ! -f "$PUSH_SWAP" ]; then
    echo -e "${RED}Error: push_swap not found!${NC}"
    exit 1
fi

if [ ! -f "$CHECKER" ]; then
    echo -e "${RED}Error: checker_Mac not found!${NC}"
    exit 1
fi

# Function to run a test case
run_test() {
    local input="$1"
    local description="$2"
    local max_ops="$3"

    echo -e "${YELLOW}Running test: $description${NC}"
    echo "Input: $input"

    # Run push_swap and count the number of operations
    operations=$($PUSH_SWAP $input | wc -l)
    echo "Number of operations: $operations"

    # Check if the output is correct
    result=$($PUSH_SWAP $input | $CHECKER $input)
    if [ "$result" == "OK" ]; then
        echo -e "${GREEN}Result: OK${NC}"
    else
        echo -e "${RED}Result: KO${NC}"
    fi

    # Check if the number of operations is within the limit
    if [ -n "$max_ops" ] && [ "$operations" -gt "$max_ops" ]; then
        echo -e "${RED}Error: Too many operations! (Max: $max_ops)${NC}"
    else
        echo -e "${GREEN}Operations within limit.${NC}"
    fi

    echo "----------------------------------------"
}

# Unit Testing
echo -e "${YELLOW}=== Unit Testing ===${NC}"

# Test stack operations
run_test "1 2" "Test stack operations (2 numbers)" ""
run_test "1 2 3" "Test stack operations (3 numbers)" ""

# Test sorting algorithms
run_test "2 1" "Test sorting (2 numbers)" ""
run_test "3 2 1" "Test sorting (3 numbers)" ""
run_test "1 3 2" "Test sorting (3 numbers)" ""

# Integration Testing
echo -e "${YELLOW}=== Integration Testing ===${NC}"

# Test with small inputs
run_test "1 2 3 4 5" "Test already sorted input (5 numbers)" ""
run_test "5 4 3 2 1" "Test reverse-sorted input (5 numbers)" ""

# Test with medium inputs
run_test "$(shuf -i 1-100 -n 100 | tr '\n' ' ')" "Test random input (100 numbers)" "700"

# Test with large inputs
run_test "$(shuf -i 1-500 -n 500 | tr '\n' ' ')" "Test random input (500 numbers)" "5500"

# Edge Cases
echo -e "${YELLOW}=== Edge Cases ===${NC}"

# Test with duplicate values
run_test "1 2 2 3" "Test duplicate values" ""

# Test with negative numbers
run_test "-1 -2 -3" "Test negative numbers" ""

# Test with single number
run_test "42" "Test single number" ""

# Test with no input
run_test "" "Test no input" ""

# Performance Testing
echo -e "${YELLOW}=== Performance Testing ===${NC}"

# Test with 100 random inputs (100 numbers each)
total_ops=0
for i in {1..100}; do
    input=$(shuf -i 1-100 -n 100 | tr '\n' ' ')
    operations=$($PUSH_SWAP $input | wc -l)
    total_ops=$((total_ops + operations))
done
average_ops=$((total_ops / 100))
echo -e "Average operations for 100 random inputs (100 numbers): ${GREEN}$average_ops${NC}"

# Test with 10 random inputs (500 numbers each)
total_ops=0
for i in {1..10}; do
    input=$(shuf -i 1-500 -n 500 | tr '\n' ' ')
    operations=$($PUSH_SWAP $input | wc -l)
    total_ops=$((total_ops + operations))
done
average_ops=$((total_ops / 10))
echo -e "Average operations for 10 random inputs (500 numbers): ${GREEN}$average_ops${NC}"

echo -e "${YELLOW}=== Testing Complete ===${NC}"
