#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <string>
#include "netlistIO.h"

#define GREEN "\033[32m"
#define RESET "\033[0m"
#define RED "\033[31m"

//Function to prompt a choice from the user
int choiceFunction();


int main()
{
    //initialize the constructor
    Netlist netlist();
    int choice = choiceFunction();
    //Make sure input file is in the same directory as the function
    netlist::netlistRead();


    
    switch (choice) {
    case 1:
        
    }
    return 0;

}




int choiceFunction() {
    int choice = 0;
    while (choice == 0) {
        std::cout << GREEN << "Welcome to the Circuit Reliability software tool page!" << RESET << std::endl;

        std::cout << "Please select a tool from the options below (Type the corresponding #:" << std::endl;
        std::cout << std::endl;
        std::cout << "1.) Circuit Statistics -" << std::endl << "Finds gate count, input/output count, longest path(critical path length) and analyzes fan - in/fan - out" << std::endl;
        std::cout << std::endl;
        std::cout << "2.) Circuit Equivalence Check -" << std::endl << "Verify whether two circuits are logically equivalent" << std::endl;
        std::cout << std::endl;
        std::cout << "3.) Truth Table Generation - " << std::endl << "Enumerates all possible inputs to show outputs" << std::endl;
        std::cout << std::endl;
        std::cout << "4.) Logic Optimization - " << std::endl << "Simplify circuits while maintaining logical equivalence" << std::endl;
        std::cout << std::endl;
        std::cout << "5.) Automatic Test Pattern Generation - " << std::endl << "Derive input patterns that expose faults in the circuit" << std::endl;
        std::cout << std::endl;
        std::cout << "6.) Verilog Code Generation - " << std::endl << "Converts parsed netlist into synthesizable verilog code" << std::endl;
        std::cout << std::endl;
        std::cout << "7.) SystemVerilog Test Pattern (Experimental) - " << std::endl << "Uses Verilog code to develop a test bench" << std::endl;
        std::cout << std::endl;
        std::cin >> choice;
        std::cout << std::endl;
    }
    return choice;
}
