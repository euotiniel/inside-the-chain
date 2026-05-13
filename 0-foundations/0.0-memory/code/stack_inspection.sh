#!/usr/bin/env bash

set -e

PID="${1:-$$}"

STACK_LIMIT=$(ulimit -s)
STACK_USAGE=$(cat /proc/"$PID"/status 2>/dev/null | grep VmStk | awk '{print $2, $3}')
STACK_MAP=$(cat /proc/"$PID"/maps 2>/dev/null | grep stack || true)

echo
echo "Stack Inspection"
echo "================"
echo

printf "%-15s %s\n" "PID:" "$PID"
printf "%-15s %s KB\n" "Stack Limit:" "$STACK_LIMIT"
printf "%-15s %s\n" "Stack Usage:" "${STACK_USAGE:-unknown}"

echo

echo "Stack Mapping"
echo "--------------"

if [ -n "$STACK_MAP" ]; then
    echo "$STACK_MAP"
else
    echo "No stack mapping found"
fi

echo