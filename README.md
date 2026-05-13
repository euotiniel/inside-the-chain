# inside-the-chain

Most people learn blockchain from the surface: wallets, tokens, smart contracts, frameworks and hype. This repository takes the opposite direction.

Not through shortcuts, but through first principles.

**Currently you can already follow**

- 0-Foundations
  - [x] [0.0 Memory Fundamentals](https://github.com/euotiniel/inside-the-chain/blob/main/0-foundations/0.0-memory/README.md)


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

The objective is to think like an engineer capable of understanding complex systems deeply.


## Structure


| Area | Description | Topics |
|---|---|---|
| **Foundations** | Low-level computing fundamentals | `memory` · `cpu` · `operating-systems` · `networking` · `processes` · `threads` · `compilers` · `databases` · `algorithms` · `data-structures` |
| **Cryptography** | Mathematical foundations of trustless systems | `hashing` · `signatures` · `elliptic-curves` · `merkle-trees` · `commitments` · `wallets` · `zero-knowledge` · `randomness` |
| **Distributed Systems** | Coordination, replication and fault tolerance between machines | `consensus` · `replication` · `byzantine-faults` · `fault-tolerance` · `distributed-storage` · `eventual-consistency` · `time-and-ordering` · `network-partitions` |
| **Economics** | Incentives, markets and human coordination systems | `amm` · `mev` · `arbitrage` · `market-making` · `tokenomics` · `behavioral-economics` · `game-theory` · `market-psychology` · `mechanism-design` · `governance` · `auction-theory` |
| **Blockchain** | Internal protocol architecture and execution | `evm` · `mempool` · `gas` · `execution` · `validators` · `state` · `storage` · `rollups` · `smart-contracts` · `security` · `transactions` · `p2p` |
| **Papers** | Research papers, notes and architecture breakdowns | `bitcoin` · `ethereum` · `uniswap` · `zksync` · `starknet` · `mev` · `scaling` |



## Module Structure

Each topic generally follows the same internal structure:

| File / Directory | Purpose |
|---|---|
| `README.md` | Overview of the topic, goals, references and implementation targets |
| `notes.md` | Concepts, explanations, observations and mental models |
| `labs.md` | Practical experiments, debugging sessions, benchmarks and exercises |
| `code/` | Implementations, prototypes, simulations and low-level experiments |

## Important

This repository is not intended to be:
- a tutorial collection,
- a crash course,
- or a "learn blockchain fast" guide.

It is intended to document the long-term process of understanding complex systems from first principles.

## License

MIT