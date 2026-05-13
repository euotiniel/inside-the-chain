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




## Topics


## References



