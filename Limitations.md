## Supported Logic Elements

### Primitives
| Gate  | Description |
|-------|-------------|
| `AND`  | Logical AND |
| `NAND` | Logical NAND |
| `OR`   | Logical OR |
| `NOR`  | Logical NOR |
| `XOR`  | Logical XOR |
| `XNOR` | Logical XNOR |
| `NOT`  | Logical NOT  single input  |
| `BUF`  | Buffer  passes input through unchanged |

### Routing
| Element | Description |
|---------|-------------|
| `MUX`   | Multiplexer  selects one of N inputs based on select lines |
| `DEMUX` | Demultiplexer  routes one input to one of N outputs |
| `TBUF`  | Tristate buffer  output can be driven high, low, or high-impedance |

### Data
| Element   | Description |
|-----------|-------------|
| `ENCODER` | Encodes N input lines into log₂(N) output lines |
| `DECODER` | Decodes log₂(N) input lines into N output lines |

### Flip-Flops
| Element   | Description |
|-----------|-------------|
| `DFF` | D Flip-Flop — captures input on clock edge, base primitive for all sequential logic |
| `TFF` | Toggle Flip-Flop — toggles output when T=1, holds when T=0, internally decomposed to DFF + XOR |
| `JKFF` | JK Flip-Flop — J sets, K resets, both high toggles, internally decomposed to DFF |
| `SRFF` | SR Flip-Flop — S sets, R resets output, S=R=1 is a forbidden state and will be flagged |
| `DFFE` | D Flip-Flop with Clock Enable — only captures input when enable is high, internally decomposed to DFF + AND |

### Registers
| Element   | Description |
|-----------|-------------|
| `SREG` | Shift Register — shifts bits left or right on each clock edge |
| `PREG` | Parallel Load Register — loads all bits simultaneously on clock edge |
| `SISO` | Serial-In Serial-Out — shifts one bit in, one bit out per clock cycle |
| `SIPO` | Serial-In Parallel-Out — shifts bits in serially, outputs all bits simultaneously |
| `PISO` | Parallel-In Serial-Out — loads all bits simultaneously, shifts out serially |
| `PIPO` | Parallel-In Parallel-Out — loads and outputs all bits simultaneously |

### Counters
| Element   | Description |
|-----------|-------------|
| `RIPPLE` | Ripple Counter — asynchronous, each flip-flop clocked by the previous flip-flop output |
| `SYNCCNT` | Synchronous Counter — all flip-flops share the same clock, up or down configurable |
| `JOHNSONCNT` | Johnson Counter — feedback shift register, produces 2N states for N flip-flops |
| `RINGCNT` | Ring Counter — single circulating bit, produces one-hot encoded states |
