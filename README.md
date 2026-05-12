# inside-the-chain

Most people learn blockchain from the surface: wallets, tokens, smart contracts, frameworks and hype. This repository takes the opposite direction.

The goal is to understand blockchain from the inside out:

- memory
- CPUs
- operating systems
- networking
- concurrency
- distributed systems
- cryptography
- economics
- consensus
- EVM internals
- mempools
- MEV
- protocol engineering

Not through shortcuts, but through first principles.

---

## Philosophy

Modern development often optimizes for speed: copying abstractions, following tutorials and shipping quickly. This repository exists to slow down and understand what is actually happening underneath the stack.

Less:
- copy-paste learning
- black-box abstractions
- framework dependency

More:
- systems thinking
- experimentation
- reading real implementations
- understanding trade-offs
- building from scratch

The objective is not just to "learn blockchain".

The objective is to think like an engineer capable of understanding complex systems deeply.

---

## Structure


| Area | Description | Topics |
|---|---|---|
| **Foundations** | Low-level computing fundamentals | `memory` · `cpu` · `operating-systems` · `networking` · `processes` · `threads` · `compilers` · `databases` · `algorithms` · `data-structures` |
| **Cryptography** | Mathematical foundations of trustless systems | `hashing` · `signatures` · `elliptic-curves` · `merkle-trees` · `commitments` · `wallets` · `zero-knowledge` · `randomness` |
| **Distributed Systems** | Coordination, replication and fault tolerance between machines | `consensus` · `replication` · `byzantine-faults` · `fault-tolerance` · `distributed-storage` · `eventual-consistency` · `time-and-ordering` · `network-partitions` |
| **Economics** | Incentives, markets and human coordination systems | `amm` · `mev` · `arbitrage` · `market-making` · `tokenomics` · `behavioral-economics` · `game-theory` · `market-psychology` · `mechanism-design` · `governance` · `auction-theory` |
| **Blockchain** | Internal protocol architecture and execution | `evm` · `mempool` · `gas` · `execution` · `validators` · `state` · `storage` · `rollups` · `smart-contracts` · `security` · `transactions` · `p2p` |
| **Papers** | Research papers, notes and architecture breakdowns | `bitcoin` · `ethereum` · `uniswap` · `zksync` · `starknet` · `mev` · `scaling` |

---

## Module Structure

Each topic generally follows the same internal structure:

| File / Directory | Purpose |
|---|---|
| `README.md` | Overview of the topic, goals, references and implementation targets |
| `notes.md` | Concepts, explanations, observations and mental models |
| `labs.md` | Practical experiments, debugging sessions, benchmarks and exercises |
| `code/` | Implementations, prototypes, simulations and low-level experiments |

---

### README.md

Acts as the entry point of the module.

Usually contains:
- why the topic matters,
- what is being studied,
- implementation goals,
- references,
- tools,
- useful links,
- deliverables.


### notes.md

Contains theoretical understanding and explanations.

This file is used for:
- concepts,
- architecture notes,
- diagrams,
- comparisons,
- implementation details,
- observations,
- open questions.

The goal is not to copy documentation, but to rewrite concepts in a way that demonstrates actual understanding.


### labs.md

Contains practical exploration.

Labs focus on:
- experiments,
- debugging,
- simulations,
- benchmarks,
- reproducing behavior,
- testing assumptions,
- implementation exercises.

Systems are understood more deeply when they are built, measured and intentionally broken.

### code/

Contains actual implementations.

Depending on the module, this may include:

| Area | Possible Implementations |
|---|---|
| Foundations | linked lists, allocators, parsers, schedulers |
| Networking | TCP servers, packet experiments, P2P nodes |
| Cryptography | wallets, hashing implementations, Merkle trees |
| Distributed Systems | replication systems, consensus simulations |
| Economics | AMMs, arbitrage bots, market simulations |
| Blockchain | mini blockchains, validators, mempools, execution engines |

---

## Important

This repository is not intended to be:
- a tutorial collection,
- a crash course,
- or a "learn blockchain fast" guide.

It is intended to document the long-term process of understanding complex systems from first principles.

---

### License

MIT