#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Netlist {
private:
	std::string netlistName;

public:
	//function to grab the data from the netlist file
	void netlistRead();
	//vector that stored netlist data where each line corresponds to a vector index
	std::vector<std::string> netlistData;
	//constructor
	Netlist();

};
