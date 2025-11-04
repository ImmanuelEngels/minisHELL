#!/bin/bash
# ==========================================
# Minishell Test Runner
# Compares minishell output vs bash
# Also checks exit codes
# ==========================================

MINISHELL="../minishell"   # Path to your minishell binary
TMP_DIR="./_tmp_results"
mkdir -p "$TMP_DIR"

RED="\033[0;31m"
GREEN="\033[0;32m"
YELLOW="\033[1;33m"
RESET="\033[0m"

PASSED=0
FAILED=0

echo -e "${YELLOW}Running minishell tests...${RESET}"
echo

for test in $(find . -type f -name "test_*.sh" | sort); do
    test_name=$(basename "$test")
    echo -n "🧩 Running $test_name ... "

    # --- Run test with bash ---
    bash "$test" > "$TMP_DIR/expected.txt" 2>&1
    expected_code=$?

    # --- Run test with minishell ---
    "$MINISHELL" < "$test" > "$TMP_DIR/actual.txt" 2>&1
    actual_code=$?

    # --- Compare output ---
    diff -u "$TMP_DIR/expected.txt" "$TMP_DIR/actual.txt" > "$TMP_DIR/diff.txt"
    diff_exit=$?

    # --- Check both output and exit code ---
    if [[ $diff_exit -eq 0 && $expected_code -eq $actual_code ]]; then
        echo -e "${GREEN}PASSED${RESET}"
        PASSED=$((PASSED+1))
    else
        echo -e "${RED}FAILED${RESET}"
        FAILED=$((FAILED+1))

        if [[ $diff_exit -ne 0 ]]; then
            echo "    └─ Output differences:"
            sed 's/^/       /' "$TMP_DIR/diff.txt" | head -n 5
        fi
        if [[ $expected_code -ne $actual_code ]]; then
            echo "    └─ Exit code mismatch: expected $expected_code, got $actual_code"
        fi
    fi
done

echo
echo -e "✅ ${GREEN}Passed:$PASSED${RESET} | ❌ ${RED}Failed:$FAILED${RESET}"
echo

# Exit non-zero if any test failed (useful for CI)
[ $FAILED -eq 0 ]

