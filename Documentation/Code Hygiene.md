I will keep track of how the code works in this document.  

To begin, we need to read the data off of the netlist file, this in turn demands a method of checking to see if the file contains what we need. For now, all we will look for is if the file is formatted correctly - meaning, is there a START and STOP signal.  

This was accomplished by the header file netlistIo, which essentially checked for the above and then stored every line as it's own string within a vector.  

Now the vector needs to be modified into an accurate representation of the digital circuit. We have a few options that can work in this regard, we can't work with a binary tree, a stack, or a queue as these all fail to meet the structural requirements of a circuit, meaning, the circuits given
will have n-inputs and m-outputs, n could be greater than, less than, or equal to m, if the gates were to be treated as nodes and the wires as vertices, then the data structures listed above would struggle.
