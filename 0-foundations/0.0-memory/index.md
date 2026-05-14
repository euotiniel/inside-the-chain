# 0.0 Memory

Understanding how memory works is fundamental for understanding how software, operating systems, virtual machines, and blockchains actually operate internally.

This chapter explores memory fundamentals, memory layout, stack, heap, pointers, dynamic allocation, and low-level memory behavior during program execution.

## Index

- [Memory](https://github.com/euotiniel/inside-the-chain/blob/main/0-foundations/0.0-memory/README.md)
- [Memory Layout](https://github.com/euotiniel/inside-the-chain/blob/main/0-foundations/0.0-memory/README.md#memory-layout)
- [Stack](https://github.com/euotiniel/inside-the-chain/blob/main/0-foundations/0.0-memory/README.md#stack)
- [Heap](https://github.com/euotiniel/inside-the-chain/blob/main/0-foundations/0.0-memory/README.md#heap)
- [Stack vs Heap](https://github.com/euotiniel/inside-the-chain/blob/main/0-foundations/0.0-memory/README.md#stack-vs-heap)
- [Conclusion](https://github.com/euotiniel/inside-the-chain/blob/main/0-foundations/0.0-memory/README.md#conclusion)

## Code

### Stack Overflow

Demonstrates how recursive function calls create new stack frames until the stack limit is exhausted.

- [`stack_overflow.c`](https://github.com/euotiniel/inside-the-chain/blob/main/0-foundations/0.0-memory/code/stack_overflow.c)

### Physical Memory Touch

Demonstrates heap allocation, virtual memory, memory pages, and how touching memory pages forces the operating system to back them with real physical RAM.

- [`physical_memory_touch.c`](https://github.com/euotiniel/inside-the-chain/blob/main/0-foundations/0.0-memory/code/physical_memory_touch.c)

## References

- [Henrique Reißen — Stack Memory vs Heap Memory](https://dev.to/reishenrique/stack-memory-vs-heap-memory-183n)

- [Linux proc filesystem documentation](https://docs.kernel.org/filesystems/proc.html)

- [Weber State University — Memory and Pointers](https://icarus.cs.weber.edu/~dab/cs1410/textbook/4.Pointers/memory.html)

- [David Gaspar — Memória em C](https://medium.com/@davidgaspar.dev/mem%C3%B3ria-em-c-c6f3803d4900)

