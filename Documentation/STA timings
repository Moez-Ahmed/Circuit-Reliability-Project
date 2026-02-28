# Static Timing Analysis (STA)

## Current Implementation

Only propagation delay per gate type is currently modeled. All instances of a given gate type share the same fixed delay value. This is used to compute the critical path length and generate conservative settle times in testbenches.

| Element | Delay (ns) |
|---------|------------|
| `AND` | 1 |
| `NAND` | 1 |
| `OR` | 1 |
| `NOR` | 1 |
| `XOR` | 2 |
| `XNOR` | 2 |
| `NOT` | 1 |
| `BUF` | 1 |
| `MUX` | 2 |
| `DEMUX` | 2 |
| `DFF` | 3 |

## Planned

The following timing parameters are not yet implemented but may be added in a future release:

**Setup Time** — the minimum time a signal must be stable before the clock edge arrives at a flip-flop. Violations indicate the circuit cannot meet timing at the target frequency.

**Hold Time** — the minimum time a signal must remain stable after the clock edge. Hold violations require minimum path analysis in addition to the maximum path analysis already used for setup.

**Clock Skew** — the difference in clock arrival time across flip-flops due to the clock distribution network. Skew tightens setup constraints and relaxes hold constraints depending on the direction of the skew between source and destination flip-flops.

## Note

Until setup time, hold time, and clock skew are modeled, timing results should be treated as approximations. Generated testbench settle times include a conservative margin to compensate.
