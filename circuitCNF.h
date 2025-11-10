#pragma once
#ifndef CIRCUIT_CNF_H
#define CIRCUIT_CNF_H

#include <vector>
#include <map>
#include <string>

typedef std::vector<int> Clause;

class circuitCNF {
private:
	int variableCounter;
	std::map<std::string, int> variableList;
	std::vector<Clause> clauses;

public:
	circuitCNF(); //Constructor
	//define functions

	int getVariable(const std::string& name); //get signals for circuit
	int getVariableCount() const;

	const std::map<std::string, int > & getVariableList() const;

	void addClause(const Clause& clause); // add clauses
	int getClause() const;


	//all gate encoding
	void addNOTGate(const std::string& input, const std::string& output);
	void addANDGate(const std::vector<std::string>& inputs, const std::string& output);
	void addORGate(const std::vector<std::string>& inputs, const std::string& output);
	void addNANDGate(const std::vector<std::string>& inputs, const std::string& output);
	void addNORGate(const std::vector<std::string>& inputs, const std::string& output);
	void addXORGate(const std::string& input1, const std::string& input2, const std::string& output);

	//test equivalency circuit
	void addTest(const std::string& output1, const std::string& output2);

	//create equivalent circuits
	std::string dimacsFormat() const;
	std::string propositionalFormat() const;//finish conversion
	//first constraint
	void addDIPConstraint(bool a, bool b, bool c, bool d, bool expectedOutput);
};





#endif
