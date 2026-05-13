# Memory

Memory, in the context of program execution, is the region where data and instructions are temporarily stored so the processor can access them quickly while an application is running. We can imagine it as a cabinet made up of several numbered drawers. Each drawer stores exactly 1 byte (8 bits), and the number assigned to each drawer is called a memory address.

> When we refer to “memory,” we are mainly referring to RAM, because it is where programs store variables, structures, stack, heap, and other temporary data during execution.

```text
┌───────────┬──────────┬──────────┬──────────┬──────────┬──────────┐
│ Address   │ 0x0001   │ 0x0002   │ 0x0003   │ 0x0004   │ 0x0005   │
├───────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
│ Byte      │ 00101111 │ 11110000 │ 00001010 │ 10101010 │ 01110111 │
└───────────┴──────────┴──────────┴──────────┴──────────┴──────────┘
```

- RAM is organized as a sequence of addresses.
- Each address identifies a specific position in memory.
- Each position stores exactly 1 byte.
- The processor accesses memory by reading and writing bytes at specific addresses.

Example:

```text
Address: 0x0003
Byte:    00001010
```

In this case:
- `0x0003` represents a specific location in memory;
- `00001010` represents the byte stored at that address;
- when accessing address `0x0003`, the processor reads the byte `00001010`.

## Memory Layout

Whenever an application is executed, the operating system creates its own virtual memory space for it. This space gives the program the impression of having a continuous and exclusive area of memory. Thus, programs normally do not access physical memory directly. Instead, they use virtual addresses, which are translated by the operating system and hardware into real positions in RAM.

Within this virtual space, the application's memory is organized into specific regions, each responsible for different types of data during the program's execution. This organization is called the memory layout.

```text
 High Memory Addresses
┌───────────────────────────────┐
│             Stack             │
└──────────────┬────────────────┘
               │
               │
               │   Free virtual space
               │   / unmapped regions
               │
               │
┌──────────────┴────────────────┐
│              Heap             │
└───────────────────────────────┘
├───────────────────────────────┤
│          BSS Segment          │
├───────────────────────────────┤
│         Data Segment          │
├───────────────────────────────┤
│         Code Segment          │
└───────────────────────────────┘
 Low Memory Addresses
```

| Region | Responsibility | Examples |
| --- | --- | --- |
| Code Segment | Stores the executable instructions of the program | Functions and compiled instructions |
| Data Segment | Stores initialized global/static variables | `int x = 10;` |
| BSS Segment | Stores uninitialized global/static variables | `int counter;` |
| Heap | Region used for dynamic memory allocation | `malloc`, `calloc`, `new` |
| Stack | Stores function calls, parameters, and local variables | Local variables inside functions |

> The layout shown is a conceptual representation; actual addresses may vary between systems and executions.

The example below prints the addresses of different types of variables and functions in memory, allowing us to visualize how each element is stored in different regions of the process memory layout.

```c
#include <stdio.h>
#include <stdlib.h>

int global_initialized = 42;
int global_uninitialized;

void function() {
    int local_variable = 10;

    int* heap_variable = malloc(sizeof(int));
    *heap_variable = 99;

    printf("Code Segment (function): %p\n", function);

    printf("Data Segment (initialized global): %p\n",
           &global_initialized);

    printf("BSS Segment (uninitialized global): %p\n",
           &global_uninitialized);

    printf("Stack (local variable): %p\n",
           &local_variable);

    printf("Heap (malloc): %p\n",
           heap_variable);

    free(heap_variable);
}

int main() {
    function();
    return 0;
}
```

When executing the program, you will get an output similar to this:

```text
Code Segment (function): 0x55b4c2c1d169
Data Segment (initialized global): 0x55b4c2c20030
BSS Segment (uninitialized global): 0x55b4c2c20038
Stack (local variable): 0x7ffd8d4e8c14
Heap (malloc): 0x55b4c5b8a2a0
```

Notice that:

- global variables remain close to each other;
- the local variable (`stack`) appears in a completely different region;
- functions also have addresses in memory.

Also notice that the addresses may change each time the program is executed. This happens because of modern virtual memory and security mechanisms, such as ASLR (*Address Space Layout Randomization*), used by the operating system to make attacks that rely on predictable addresses more difficult.

## Stack

The stack is a region of memory primarily used to store function calls, parameters, return addresses, and local variables during program execution.

Every time a function is called, the CPU creates a new block in memory called a **stack frame**. This operation is extremely fast because stack allocation is usually performed through simple CPU instructions that adjust the stack pointer register (`SP`).

When the function finishes, the stack frame is automatically removed by moving the stack pointer back to its previous position.

```text
┌──────────────────────────┐
│ functionB() stack frame  │ ← Top of the stack
├──────────────────────────┤
│ functionA() stack frame  │
├──────────────────────────┤
│ main() stack frame       │
└──────────────────────────┘
```

The stack follows a **Last In, First Out (LIFO)** structure.

```
Execution flow:

1. `main()` creates its stack frame.
2. `functionA()` creates another frame above it.
3. `functionB()` creates another frame.
4. When `functionB()` finishes, its frame is removed.
5. Then `functionA()` finishes and its frame is removed.
6. Finally, `main()` finishes.
```

Although stack frames are considered "removed" after a function returns, the memory itself is usually **not physically erased**.

In practice, the CPU simply updates a special register called the **Stack Pointer (SP)**, which keeps track of the current top of the stack.

```text
Before function returns:

┌──────────────────┐
│ functionB frame  │ ← Stack Pointer (SP)
├──────────────────┤
│ functionA frame  │
└──────────────────┘

After functionB returns:

┌──────────────────┐
│ old functionB    │ ← data may still physically exist
│ memory region    │
├──────────────────┤
│ functionA frame  │ ← Stack Pointer (SP)
└──────────────────┘
```

Instead of clearing the memory byte by byte, the CPU simply moves the stack pointer back to the previous position, marking that region as reusable.

This means old stack data may still temporarily remain in memory until another function overwrites it.

The stack has a limited size. If too many stack frames are created, or if local variables consume excessive memory, the stack may exceed its allocated limit.

This condition is called a **stack overflow**.

Common causes include:
- infinite recursion;
- extremely deep recursion;
- very large local arrays.

Example:

```c
void recursive() {
    recursive();
}
```

This function keeps creating stack frames until the program crashes with a stack overflow.


You can [download and run this script]() on your Linux machine (Ubuntu, for example) to inspect stack limits, stack mappings, and stack usage during program execution.

After making the script executable and running it:

```bash
chmod +x stack_inspection.sh
./stack_inspection.sh
```

you will get an output similar to this:

```text
Stack Inspection
================

PID:            6787
Stack Limit:    16384 KB
Stack Usage:    136 kB

Stack Mapping
--------------
7fff58537000-7fff58559000 rw-p 00000000 00:00 0 [stack]
```

From this output, we can observe:

- the process identifier (`PID`);
- the maximum stack size allowed for the process (`Stack Limit`);
- the current amount of stack memory being used (`Stack Usage`);
- the virtual memory region reserved for the stack (`[stack]`).

In the stack mapping:

```text
7fff58537000-7fff58559000
```

the first address represents the beginning of the stack region, while the second represents the end of the mapped stack space in virtual memory.

The flags:

```text
rw-p
```

mean that the region is:
- `r` → readable
- `w` → writable
- `p` → private to the process

This allows us to directly observe how the operating system organizes stack memory during program execution.

## Heap

The heap is a region of memory used to store data that needs to exist dynamically during program execution. The heap is more like a warehouse: you can put things there, and they remain until someone explicitly removes them.

Unlike the stack, where local variables have a short and automatic lifetime (born when the function enters, dying when it exits), the heap allows you to create data that can continue to exist even after a function ends. This makes it essential for dynamic structures, large volumes of data, objects created at runtime, data shared between functions, and applications whose memory size cannot be predicted at compile time.

When a program needs dynamic memory, it makes a request to the system through the allocator (memory allocator).

In C, this typically happens using:

```c
malloc()
calloc()
realloc()
free()
```

Example:

```c
int* ptr = malloc(sizeof(int));
```

Even when using the heap, the `ptr` variable remains a local variable of the function. This means it will normally be stored on the stack.

What `malloc()` does is:
- reserve a region of memory on the heap;
- return the address of that region;
- store that address inside `ptr`.

```text
Stack                                      Heap

address 0x7ffdd8a30130                    address 0x62c6f2ae12a0
┌────────────────────┐                    ┌────────────────────┐
│ ptr                │                    │         ?          │
│ value:0x62c6...  ─────────────────────▶ │                    │
└────────────────────┘                    └────────────────────┘
```

Notice that:
- `ptr` is stored on the stack;
- the value stored inside `ptr` is an address;
- that address points to a region of the heap;
- the heap memory has not yet been initialized.

In other words:
- the stack is still being used;
- but now it stores only a pointer to data located in another region of memory.

After:

```c
*ptr = 42;
```

the program accesses the address stored in `ptr` and writes the value `42` to that region of the heap.

```text
Stack                                      Heap

address 0x7ffdd8a30130                    address 0x62c6f2ae12a0
┌────────────────────┐                    ┌────────────────────┐
│ ptr                │                    │         42         │
│ value:0x62c6...  ─────────────────────▶ │                    │
└────────────────────┘                    └────────────────────┘
```

Now:
- `ptr` remains stored on the stack, but pointing to the address on the heap;
- the value `42` is stored on the heap.

Complete example:

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int* ptr = malloc(sizeof(int));
    *ptr = 42;

    printf("Address of pointer variable (&ptr): %p\n", (void*)&ptr);
    printf("ptr stored inside pointer (ptr): %p\n", (void*)ptr);
    printf("Heap memory address: %p\n", (void*)ptr);
    printf("ptr stored in heap (*ptr): %d\n", *ptr);
    free(ptr);

    return 0;
}
```

Possible output:

```text
Address of pointer variable (&ptr): 0x7fff7b138d70
ptr stored inside pointer (ptr): 0x5d84636f82a0
Heap memory address: 0x5d84636f82a0
ptr stored in heap (*ptr): 42
```

Notice that:
- `&ptr` shows where the pointer variable is stored (stack);
- `ptr` shows the address stored inside the pointer;
- that address belongs to the heap;
- `*ptr` accesses the content stored in that region of the heap.

In C, heap memory is managed manually. This means that all memory allocated with `malloc()`, `calloc()`, or `realloc()` must be explicitly released by the programmer using:

```c
free(ptr);
```

When allocated memory is not properly released, it continues to occupy space on the heap even though the program no longer has useful access to that region.

This problem is called a **memory leak**.

Example:

```c
void leak() {
    int* data = malloc(sizeof(int));

    *data = 42;

    // free(data); missing
}
```

Each call to this function:
- allocates a new region on the heap;
- consumes more memory;
- never returns that memory to the system.

In small applications this may seem irrelevant, but in long-running systems such as servers, games, browsers, blockchains, and databases, memory leaks can accumulate continuously until they consume large amounts of RAM.

To reduce this problem, some languages use **Garbage Collection (GC)**, an automatic memory management mechanism responsible for identifying and freeing heap objects that are no longer being used by the program.

In these languages:
- the runtime monitors objects allocated on the heap;
- identifies which objects still have valid references;
- automatically removes inaccessible objects.

In C:
- there is no standard garbage collector;
- heap management is manual;
- the programmer has greater control over memory;
- but also assumes greater responsibility and risk.

It is possible to visualize the heap region directly on Linux using:

```bash
cat /proc/self/maps | grep heap
```

Example output:

```text
5af6add15000-5af6add36000 rw-p 00000000 00:00 0 [heap]
```

| Field                        | Meaning                                                         |
| ---------------------------- | --------------------------------------------------------------- |
| `5af6add15000-5af6add36000`  | Virtual address range reserved for the heap                     |
| `5af6add15000`               | Start address of the heap                                       |
| `5af6add36000`               | End address of the heap                                         |
| `rw-p`                       | Region permissions (`r` = read, `w` = write, `p` = private)     |
| `00000000`                   | Offset used in the mapping                                      |
| `00:00`                      | Device identifier associated with the mapping                   |
| `0`                          | Inode associated with the mapped region                         |
| `[heap]`                     | Indicates that the region belongs to the process heap           |

This is the region where functions such as:

```c
malloc()  - allocates a region of memory on the heap
calloc()  - allocates memory and initializes the bytes to zero
realloc() - resizes a previously allocated region
```

perform dynamic memory allocations during program execution.

It is also possible to view the current heap size using:

```bash
cat /proc/self/status | grep VmData
```

Example output:

```text
VmData:     356 kB
```

| Field     | Meaning                                                                   |
|-----------|---------------------------------------------------------------------------|
| `VmData`  | Amount of memory used by the process's data segment, including the heap   |

The value:
- is typically displayed in `kB`;
- may grow as new dynamic allocations are performed.

## Stack vs Heap

| Characteristic | Stack | Heap | When to use |
|---|---|---|---|
| Allocation | Automatic | Dynamic / manual | Stack for simple data; heap for flexible data |
| Speed | Very fast | Slower | Stack for maximum performance |
| Memory deallocation | Automatic | Manual (`free`) or GC | Heap when data must survive function returns |
| Lifetime | Function scope | Defined by the programmer | Heap for persistent data |
| Size | Limited | Generally larger | Heap for large structures |
| Organization | LIFO | Non-sequential | Stack for predictable flow |
| Common risks | Stack overflow | Memory leaks / dangling pointers | Choice depends on acceptable risk |
| Example | `int x = 10;` | `int* p = malloc(sizeof(int));` | Stack for local variables; heap for dynamic allocation |


## Topics


## References



