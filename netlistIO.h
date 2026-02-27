#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Netlist {
	private:
		int gateCount;
		int inputCount;
		int outputCount;
		int wireCount;
		std::string netlistName;
		
	public:
		//function to grab the data from the netlist file
		void netlistRead();
		//vector that stored netlist data where each line corresponds to a vector index
		std::vector<std::string> netlistData;
		//vector that stores netlist data in CNF form
		std::vector<std::string> netlistCNF;
		//constructor
		Netlist();
		

};
