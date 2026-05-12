# ROADMAP

> Long-term roadmap for understanding blockchain from first principles.

---

## Foundations

Low-level computing fundamentals.

| Module | Topics | Implementations |
|---|---|---|
| Memory | stack, heap, pointers, virtual memory | linked lists, allocators |
| CPU | registers, syscalls, assembly | assembly experiments |
| Operating Systems | scheduling, filesystems, processes | mini shell |
| Networking | TCP/IP, sockets, DNS, HTTP | TCP server, P2P node |
| Processes | fork, exec, pipes | process manager |
| Threads | mutexes, race conditions | concurrency simulations |
| Compilers | parsing, ASTs, bytecode | parser experiments |
| Databases | indexes, storage engines | mini storage engine |
| Algorithms | complexity, graphs | algorithm implementations |
| Data Structures | trees, queues, hash maps | low-level implementations |

---

## Cryptography

Mathematical foundations of trustless systems.

| Module | Topics | Implementations |
|---|---|---|
| Hashing | SHA256, Keccak | hashing implementations |
| Signatures | public/private keys | wallet generation |
| Elliptic Curves | ECC fundamentals | ECC experiments |
| Merkle Trees | proofs and verification | Merkle implementation |
| Commitments | cryptographic commitments | commitment experiments |
| Zero Knowledge | zk proofs, zk systems | zk simulations |
| Randomness | distributed randomness | randomness experiments |

---

## Distributed Systems

Coordination and fault tolerance between machines.

| Module | Topics | Implementations |
|---|---|---|
| Consensus | PoW, PoS, PBFT | consensus simulations |
| Replication | distributed state | replication systems |
| Byzantine Faults | adversarial coordination | Byzantine simulations |
| Fault Tolerance | resilience and recovery | recovery experiments |
| Distributed Storage | distributed persistence | distributed storage layer |
| Eventual Consistency | synchronization delays | consistency simulations |
| Time & Ordering | Lamport clocks | ordering systems |
| Network Partitions | split-brain problems | partition simulations |

---

## Economics

Markets, incentives and human coordination systems.

| Module | Topics | Implementations |
|---|---|---|
| AMMs | CPMMs, liquidity curves | AMM implementation |
| MEV | extraction and ordering | MEV simulations |
| Arbitrage | market inefficiencies | arbitrage bots |
| Market Making | liquidity provisioning | market maker simulations |
| Tokenomics | emissions and incentives | token models |
| Behavioral Economics | reflexivity, FOMO, herd behavior | psychology simulations |
| Game Theory | coordination and attacks | strategy simulations |
| Market Psychology | narratives and sentiment | market behavior analysis |
| Mechanism Design | incentive systems | governance experiments |
| Governance | DAOs and voting | governance simulations |
| Auction Theory | gas and blockspace auctions | fee market simulations |

---

## Blockchain

Internal blockchain architecture and execution.

| Module | Topics | Implementations |
|---|---|---|
| EVM | execution model, bytecode | EVM experiments |
| Mempool | transaction propagation | mempool simulation |
| Gas | execution pricing | gas analysis |
| Execution | transaction execution flow | execution engine |
| Validators | staking and validation | validator simulation |
| State | blockchain state management | state experiments |
| Storage | trie structures and persistence | storage layer |
| Rollups | scalability systems | rollup experiments |
| Smart Contracts | Solidity internals | contract systems |
| Security | exploits and attacks | exploit reproductions |
| Transactions | signing and propagation | transaction pipeline |
| P2P | peer discovery and networking | peer-to-peer layer |

---

## Papers

Research papers, architecture notes and implementation breakdowns.

| Area | Targets |
|---|---|
| Bitcoin | Bitcoin whitepaper |
| Ethereum | Ethereum paper |
| DeFi | Uniswap v2/v3 |
| Scaling | zkSync, StarkNet |
| MEV | Flash Boys 2.0 and related papers |
| Consensus | distributed systems papers |

---

# Experiments

Practical implementations and simulations.

| Project | Focus |
|---|---|
| Mini Blockchain | blockchain fundamentals |
| P2P Node | networking |
| Mempool Simulation | transaction ordering |
| CPMM | AMM mechanics |
| Consensus Simulation | distributed coordination |
| Validator System | staking and validation |
| MEV Simulation | extraction strategies |

---

# Long-Term Objective

To eventually become capable of:
- understanding protocol internals,
- designing distributed systems,
- reasoning about incentives,
- reading production blockchain clients,
- implementing systems from scratch,
- and contributing to protocol-level engineering and research.