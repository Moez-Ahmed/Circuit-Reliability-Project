# SAT-Based EDA Tool for Formal Circuit Verification

A SAT-based Electronic Design Automation (EDA) tool for formal verification and analysis of combinational circuits. Circuits are described as netlists and internally converted to Conjunctive Normal Form (CNF) for SAT-based reasoning.

---

## Features

- **Circuit Equivalence Checking** — Formally verify whether two circuits are logically equivalent
- **Automatic Test Pattern Generation (ATPG)** — Derive input patterns that expose faults in a circuit then builds system verilog test bench
- **Logic Optimization** — Simplify circuits while preserving logical equivalence
- **Verilog Code Generation** — Export a parsed netlist as synthesizable Verilog

---

## Netlist Format

Circuits are described as a plain-text netlist, one gate per line, in the following format:

```
GATE_TYPE  Input1  Input2  ...  InputN  Output
```

The **first token** is the gate type, the **last token** is the output signal, and everything in between are inputs. The number of inputs is variable.

### Example

```
AND  A  B  C  W1
OR   W1 D  W2
NOT  W2    OUT
```

This describes a circuit where:
- `A`, `B`, `C`, `D` are primary inputs
- `W1`, `W2` are internal wires
- `OUT` is the primary output

---

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
| `NOT`  | Logical NOT — single input  |
| `BUF`  | Buffer — passes input through unchanged |

### Routing
| Element | Description |
|---------|-------------|
| `MUX`   | Multiplexer — selects one of N inputs based on select lines |
| `DEMUX` | Demultiplexer — routes one input to one of N outputs |
| `TBUF`  | Tristate buffer — output can be driven high, low, or high-impedance |

### Data
| Element   | Description |
|-----------|-------------|
| `ENCODER` | Encodes N input lines into log₂(N) output lines |
| `DECODER` | Decodes log₂(N) input lines into N output lines |

---

## How It Works

Internally, each gate is converted into a set of CNF clauses using the Tseitin transformation. This produces an equisatisfiable CNF formula that can be passed to a SAT solver.

```
Netlist → Parse → CNF Encoding → SAT Solver → Result
                ↘
                 Verilog Output
```

- **Equivalence checking** encodes both circuits and asserts they differ (miter circuit) — UNSAT means equivalent
- **ATPG** encodes a fault model and asks the SAT solver for a satisfying input assignment
- **Optimization** iteratively checks if a reduced circuit is equivalent to the original

---

## Notes

- Only **combinational logic** is supported — no flip-flops, latches, or clocked elements _But if someone were to ask I would be happy to try sequential logic_
- Primary inputs and outputs are inferred automatically from the netlist — signals never driven by a gate are treated as inputs
- Signal names are case-sensitive
