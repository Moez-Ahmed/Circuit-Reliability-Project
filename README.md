# Circuit-Reliability-Project
A SAT-based EDA tool for formal circuit verification and analysis. Features include Circuit Equivalence checking, Automatic Test Pattern Generation, and logic optimization, implemented by converting circuit netlists into conjunctive normal form


The intention is to convert a circuit netlist of the following form:

Gate Input1 Input2  Output  
Gate2 Input3 InputN Output2  



into a combinational circuit that can further be operated on using the above commands.  


The current list of logic devices that work are:  

Primitives:
+AND, NAND
+OR, NOR
+XOR, XNOR
+NOR, BUF
Routing:
+MUX, DEMUX
+TBUF
Data:
+Encoder, Decoder
Arithmetic:
+Half Adder, Full Adder
+Ripple Carry Adder
+Comparator
+ALU
Lookup:
+ROM

