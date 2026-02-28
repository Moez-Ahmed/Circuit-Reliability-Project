#include "netlistIO.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>


Netlist::Netlist() {}

void Netlist::netlistRead() {
    std::ifstream infile;
    std::string tempLine;

    //infinite loop to get the correct file name
    std::cout << "Please input the name of the netlist file: ";
    while (true) {
        netlistData.clear();
        std::getline(std::cin, netlistName);
        infile.open(netlistName);
        if (!infile) {
            infile.clear();
            std::cout << "Invalid file. Please enter a valid netlist file name: " << std::flush;
            continue;
        }
        //now that we have the file name, it's time to read the data on the file
        if (!std::getline(infile, tempLine) || tempLine != "START") {
            std::cout << "Error, the file does not follow the standard format, please check the github for tips on writing the file" << std::endl;
            std::cout << "Please enter a valid netlist file name: " << std::flush;

            //As we have an error, this resets the ifstream bits
            infile.close();
            infile.clear();
            continue;
        }
        //The file works so we continue from here so we start to read through the file
        while (getline(infile, tempLine)) {
            netlistData.push_back(tempLine);
        }

        if (netlistData.back() != "STOP") {
            std::cout << "Error, the file does not follow the standard format, please check the github for tips on writing the file" << std::endl;
            std::cout << "Please enter a valid netlist file name: " << std::flush;

            //As we have an error, this resets the ifstream bits
            infile.close();
            infile.clear();
            continue;
        }
        //finally cut out the STOP line
        netlistData.pop_back();

        break;

    }


}
