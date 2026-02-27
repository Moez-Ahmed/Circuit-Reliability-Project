#include "netlistIO.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>


Netlist::Netlist() : gateCount(0), inputCount(0), outputCount(0), wireCount(0) {}

void Netlist::netlistRead() {
    std::ifstream infile;

    //infinite loop to get the correct file name
    std::cout << "Please input the name of the netlist file: ";
    while (true) {
        std::string infilename;
        std::getline(std::cin, netlistName);
        infile.open(infilename);
        if (infile) break;
        std::cout << "Invalid file. Please enter a valid netlist file name: " << std::flush;
    }

    //now that we have the file name, it's time to read the data on the file

}
