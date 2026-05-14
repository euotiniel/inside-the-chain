/*
 * Demonstrates a stack overflow caused by infinite recursion.
 *
 * Every time recursion() calls itself, the program creates
 * a new stack frame.
 *
 * A stack frame usually stores data related to that specific
 * function call, such as:
 *
 * - function parameters, like i
 * - local variables, like local
 *
 * This program has no stopping condition.
 * Because of that, stack frames keep accumulating until the
 * stack limit is reached.
 *
 * The address of the local variable is printed to observe
 * how the stack behaves. On most Linux x86_64 systems, the stack
 * grows toward lower memory addresses, so the printed addresses
 * usually decrease as i increases.
 *
 * The addresses may change between executions because of ASLR
 * (Address Space Layout Randomization), but within the same
 * execution they should follow a visible pattern.
 *
 * Eventually, the program exhausts the available stack space
 * and crashes with a `Segmentation Fault`.
 */

#include <stdio.h>

void recursion(int i) {
    int local;
    printf("i = %d | address = %p\n", i, (void*)&local);
    recursion(i + 1);
}

int main() {
    recursion(0);
    return 0;
}