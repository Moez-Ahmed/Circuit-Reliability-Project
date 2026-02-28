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


