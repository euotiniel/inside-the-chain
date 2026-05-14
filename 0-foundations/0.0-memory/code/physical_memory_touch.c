/*
 * Demonstrates how dynamically allocated memory can become
 * backed by real physical RAM.
 *
 * The program:
 *
 * 1. Shows the current system memory usage using `free -h`
 * 2. Allocates 5 GB of memory on the heap using malloc()
 * 3. Touches the allocated memory page by page
 * 4. Shows the memory usage again
 * 5. Waits for user input before releasing the memory
 *
 * Modern operating systems use virtual memory.
 * Physical RAM is usually assigned only when memory pages
 * are actually accessed.
 *
 * The expression: 5 * 1024ULL * 1024 * 1024
 * represents 5 GB in bytes: 5,368,709,120 bytes
 * The `ULL` suffix means: Unsigned Long Long
 * which forces the calculation to use a large integer type.
 *     
 * The loop increments by 4096 bytes because 4096 bytes (4 KB)
 * is the typical memory page size on many systems.
 *
 * By writing one byte per page: memory[i] = 1;
 *
 * the program forces the operating system to back those pages
 * with real physical RAM.
 */

#include <stdio.h>
#include <stdlib.h>

void show_memory() {
    system("free -h");
}

int main() {

    long total_memory = 5 * 1024ULL * 1024 * 1024;
    char *memory = malloc(total_memory);

    printf("Before:\n");
    show_memory();

    for (unsigned long i = 0; i < total_memory; i += 4096)
        memory[i] = 1;

    printf("\nAfter touching 5 GB:\n");
    show_memory();

    getchar();
    free(memory);

    return 0;
}